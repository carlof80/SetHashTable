# CMake generated Testfile for 
# Source directory: C:/Users/famari_carlo/source/repos/SetHashTable
# Build directory: C:/Users/famari_carlo/source/repos/SetHashTable/out/build/x64-Debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(CompileTest "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" "--build" "C:/Users/famari_carlo/source/repos/SetHashTable/out/build/x64-Debug" "--target" "SetHashTable_test")
set_tests_properties(CompileTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;132;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
add_test(SetTest1 "./SetHashTable_test" "[SetTest]")
set_tests_properties(SetTest1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;137;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
add_test(SetTest2 "./SetHashTable_test" "[StoreTest]")
set_tests_properties(SetTest2 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;140;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
add_test(SetTest3 "./SetHashTable_test" "[PolymorphismTest]")
set_tests_properties(SetTest3 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;143;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
add_test(SetTest4 "./SetHashTable_test" "[IteratorTest]")
set_tests_properties(SetTest4 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;146;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
add_test(SetTest5 "./SetHashTable_test" "[ProbingSetTest]")
set_tests_properties(SetTest5 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;149;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
add_test(ValgrindTest1 "valgrind" "--leak-check=full" "--show-leak-kinds=all" "--track-origins=yes" "./SetHashTable_test" "[SetTest]")
set_tests_properties(ValgrindTest1 PROPERTIES  WORKING_DIRECTORY "C:/Users/famari_carlo/source/repos/SetHashTable/build" _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;154;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
add_test(ValgrindTest2 "valgrind" "--leak-check=full" "--show-leak-kinds=all" "--track-origins=yes" "./SetHashTable_test" "[StoreTest]")
set_tests_properties(ValgrindTest2 PROPERTIES  WORKING_DIRECTORY "C:/Users/famari_carlo/source/repos/SetHashTable/build" _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;160;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
