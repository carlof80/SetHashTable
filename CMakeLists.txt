#CMakeList.txt : progetto CMake per SetHashTable.Includere l'origine e definire
#qui la logica specifica del                               progetto.
#
cmake_minimum_required (VERSION 3.8)

project ("SetHashTable")

#-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
### COMPILER FLAGS ###

include(CheckCXXCompilerFlag)

#CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
#if (COMPILER_SUPPORTS_CXX14)
#    add_compile_options("-std=c++17")
#else()
#    message(FATAL_ERROR "Compiler ${CMAKE_CXX_COMPILER} has no C++17 support.")
#endif()

CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
if (_cpp_latest_flag_supported)
    add_compile_options("/std:c++latest")
endif()

#if(MSVC)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
#endif(MSVC)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    add_compile_options("-Weverything")
    add_compile_options("-Wno-c++98-compat")
    add_compile_options("-Wno-c++98-compat-pedantic")
    add_compile_options("-Wno-padded")
    add_compile_options("-Wno-undefined-func-template")
    add_compile_options("-Wno-documentation-unknown-command")
    add_compile_options("-Wno-global-constructors")
    add_compile_options("-Wno-exit-time-destructors")
    add_compile_options("-Wno-sign-conversion")
    add_compile_options("-Wno-weak-vtables")
    add_compile_options("-Wno-weak-template-vtables")
    add_compile_options("-Wno-documentation") ##########
elseif (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-Wpedantic")
endif()

#add_compile_options("-Werror")

#-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
### BUILD TYPE ###

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options("-O3")
    add_compile_options("-DNDEBUG")

elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (CMAKE_COMPILER_IS_GNUCXX)
        add_compile_options("-ggdb3")
    elseif (CMAKE_CXX_COMPILER_ID EQUAL "Clang")
        add_compile_options("-ggdb")
    else()
        add_compile_options("-g")
    endif()

elseif (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    if (CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_EXE_LINKER_FLAGS ${
    CMAKE_EXE_LINKER_FLAGS} "--coverage")
        add_compile_options("--coverage")
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        add_compile_options("-fprofile-instr-generate")
        add_compile_options("-fcoverage-mapping")
        set(CMAKE_EXE_LINKER_FLAGS ${
    CMAKE_EXE_LINKER_FLAGS}
                                  "-fprofile-instr-generate -fcoverage-mapping")
    endif()

elseif (CMAKE_BUILD_TYPE STREQUAL "SANITIZE" AND
        CMAKE_CXX_COMPILER_ID EQUAL "Clang")

    add_compile_options("-O1")
    add_compile_options("-g")
    add_compile_options("-fno-omit-frame-pointer")
    add_compile_options("-fno-optimize-sibling-calls")

    add_compile_options("-fsanitize=address")
    add_compile_options("-fsanitize=leak")
    add_compile_options("-fsanitize=memory")
    add_compile_options("-fsanitize-memory-track-origins")
    add_compile_options("-fsanitize=undefined")
    add_compile_options("-fsanitize=integer")
    add_compile_options("-fsanitize=nullability")

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
endif()

#TARGETS

add_custom_target(clean-all
                  COMMAND rm -rf ${PROJECT_SOURCE_DIR}/build/*
                  COMMAND rm -rf ${PROJECT_SOURCE_DIR}/doc/*    
                  COMMENT "scan-build Static Analysis")

find_program(DOXYGEN_FOUND doxygen)
if (DOXYGEN_FOUND)
    add_custom_target(doc
                      COMMAND doxygen ./doxygen.cfg
                      COMMENT "Code documentation")
endif()

#------------------------------------------------------------------------------
### BUILD LIBRARY ###

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON) # for clang-tidy
include_directories(${PROJECT_SOURCE_DIR}/include 
                    ${PROJECT_SOURCE_DIR}/lib 
                    ${PROJECT_SOURCE_DIR}/src)
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(hashset ${SRCS})

#add_executable(SetHashTable EXCLUDE_FROM_ALL ${PROJECT_SOURCE_DIR}/examples/SetHashTable.cpp)
add_executable(SetHashTable_test EXCLUDE_FROM_ALL ${PROJECT_SOURCE_DIR}/test/Test.cpp)
set_property(TARGET SetHashTable_test PROPERTY CXX_STANDARD 17)

target_link_libraries(SetHashTable_test hashset)
#target_link_libraries(SetHashTable hashset)

# TEST
enable_testing()

ADD_TEST(NAME CompileTest
         COMMAND "${CMAKE_COMMAND}"
         --build "${CMAKE_BINARY_DIR}"
         --target SetHashTable_test)

ADD_TEST(NAME SetTest1
         COMMAND ./SetHashTable_test [SetTest])

ADD_TEST(NAME SetTest2
         COMMAND ./SetHashTable_test [StoreTest])

ADD_TEST(NAME SetTest3
         COMMAND ./SetHashTable_test [PolymorphismTest])

ADD_TEST(NAME SetTest4
         COMMAND ./SetHashTable_test [IteratorTest])

ADD_TEST(NAME SetTest5
         COMMAND ./SetHashTable_test [ProbingSetTest])

find_program(VALGRIND_FOUND valgrind)
if (VALGRIND_FOUND)
    ADD_TEST(NAME ValgrindTest1
             WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
             COMMAND valgrind --leak-check=full --show-leak-kinds=all
                              --track-origins=yes
                              ./SetHashTable_test [SetTest])

    ADD_TEST(NAME ValgrindTest2
             WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
             COMMAND valgrind --leak-check=full --show-leak-kinds=all
                              --track-origins=yes
                              ./SetHashTable_test [StoreTest])
endif()