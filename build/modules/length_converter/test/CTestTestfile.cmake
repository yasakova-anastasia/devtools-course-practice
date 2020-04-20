# CMake generated Testfile for 
# Source directory: C:/Users/Stacy/devtools-course-practice/modules/length_converter/test
# Build directory: C:/Users/Stacy/devtools-course-practice/build/modules/length_converter/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(length_converter_gtest "C:/Users/Stacy/devtools-course-practice/build/bin/test_length_converter.exe")
  set_tests_properties(length_converter_gtest PROPERTIES  LABELS "length_converter" _BACKTRACE_TRIPLES "C:/Users/Stacy/devtools-course-practice/modules/length_converter/test/CMakeLists.txt;16;add_test;C:/Users/Stacy/devtools-course-practice/modules/length_converter/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(length_converter_gtest "C:/Users/Stacy/devtools-course-practice/build/bin/test_length_converter.exe")
  set_tests_properties(length_converter_gtest PROPERTIES  LABELS "length_converter" _BACKTRACE_TRIPLES "C:/Users/Stacy/devtools-course-practice/modules/length_converter/test/CMakeLists.txt;16;add_test;C:/Users/Stacy/devtools-course-practice/modules/length_converter/test/CMakeLists.txt;0;")
else()
  add_test(length_converter_gtest NOT_AVAILABLE)
endif()
