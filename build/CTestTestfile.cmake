# CMake generated Testfile for 
# Source directory: C:/Users/famari_carlo/source/repos/SetHashTable
# Build directory: C:/Users/famari_carlo/source/repos/SetHashTable/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(CompileTest "C:/Program Files/CMake/bin/cmake.exe" "--build" "C:/Users/famari_carlo/source/repos/SetHashTable/build" "--target" "SetHashTable_test")
  set_tests_properties(CompileTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;157;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(CompileTest "C:/Program Files/CMake/bin/cmake.exe" "--build" "C:/Users/famari_carlo/source/repos/SetHashTable/build" "--target" "SetHashTable_test")
  set_tests_properties(CompileTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;157;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(CompileTest "C:/Program Files/CMake/bin/cmake.exe" "--build" "C:/Users/famari_carlo/source/repos/SetHashTable/build" "--target" "SetHashTable_test")
  set_tests_properties(CompileTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;157;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(CompileTest "C:/Program Files/CMake/bin/cmake.exe" "--build" "C:/Users/famari_carlo/source/repos/SetHashTable/build" "--target" "SetHashTable_test")
  set_tests_properties(CompileTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;157;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
else()
  add_test(CompileTest NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(SetTest1 "./SetHashTable_test" "[SetTest]")
  set_tests_properties(SetTest1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;162;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(SetTest1 "./SetHashTable_test" "[SetTest]")
  set_tests_properties(SetTest1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;162;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(SetTest1 "./SetHashTable_test" "[SetTest]")
  set_tests_properties(SetTest1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;162;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(SetTest1 "./SetHashTable_test" "[SetTest]")
  set_tests_properties(SetTest1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;162;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
else()
  add_test(SetTest1 NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(SetTest2 "./SetHashTable_test" "[StoreTest]")
  set_tests_properties(SetTest2 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;165;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(SetTest2 "./SetHashTable_test" "[StoreTest]")
  set_tests_properties(SetTest2 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;165;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(SetTest2 "./SetHashTable_test" "[StoreTest]")
  set_tests_properties(SetTest2 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;165;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(SetTest2 "./SetHashTable_test" "[StoreTest]")
  set_tests_properties(SetTest2 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;165;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
else()
  add_test(SetTest2 NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(SetTest3 "./SetHashTable_test" "[PolymorphismTest]")
  set_tests_properties(SetTest3 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;168;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(SetTest3 "./SetHashTable_test" "[PolymorphismTest]")
  set_tests_properties(SetTest3 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;168;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(SetTest3 "./SetHashTable_test" "[PolymorphismTest]")
  set_tests_properties(SetTest3 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;168;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(SetTest3 "./SetHashTable_test" "[PolymorphismTest]")
  set_tests_properties(SetTest3 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;168;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
else()
  add_test(SetTest3 NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(SetTest4 "./SetHashTable_test" "[IteratorTest]")
  set_tests_properties(SetTest4 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;171;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(SetTest4 "./SetHashTable_test" "[IteratorTest]")
  set_tests_properties(SetTest4 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;171;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(SetTest4 "./SetHashTable_test" "[IteratorTest]")
  set_tests_properties(SetTest4 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;171;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(SetTest4 "./SetHashTable_test" "[IteratorTest]")
  set_tests_properties(SetTest4 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;171;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
else()
  add_test(SetTest4 NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(SetTest5 "./SetHashTable_test" "[ProbingSetTest]")
  set_tests_properties(SetTest5 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;174;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(SetTest5 "./SetHashTable_test" "[ProbingSetTest]")
  set_tests_properties(SetTest5 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;174;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(SetTest5 "./SetHashTable_test" "[ProbingSetTest]")
  set_tests_properties(SetTest5 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;174;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(SetTest5 "./SetHashTable_test" "[ProbingSetTest]")
  set_tests_properties(SetTest5 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;174;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
else()
  add_test(SetTest5 NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(SetTest6 "./SetHashTable_test" "[TimeTest]")
  set_tests_properties(SetTest6 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;177;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(SetTest6 "./SetHashTable_test" "[TimeTest]")
  set_tests_properties(SetTest6 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;177;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(SetTest6 "./SetHashTable_test" "[TimeTest]")
  set_tests_properties(SetTest6 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;177;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(SetTest6 "./SetHashTable_test" "[TimeTest]")
  set_tests_properties(SetTest6 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;177;ADD_TEST;C:/Users/famari_carlo/source/repos/SetHashTable/CMakeLists.txt;0;")
else()
  add_test(SetTest6 NOT_AVAILABLE)
endif()
