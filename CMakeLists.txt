cmake_minimum_required(VERSION 3.2)
project(fbpfsm_root C)
set(CMAKE_C_STANDARD 99)

# Enable code coverage
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/externals/CMake-codecov/cmake" ${CMAKE_MODULE_PATH})
find_package(codecov)

# CTest
enable_testing()

# Add libraries
add_subdirectory(externals)
add_subdirectory(source)

macro(setup_target NAME TIMEOUT)
  add_coverage(${NAME})
  target_compile_options(${NAME} PRIVATE -g -Wall -Wextra -pedantic)
  target_include_directories(${NAME} PRIVATE source externals/Unity/src)
  target_link_libraries(${NAME} FFSM Unity)
  add_test(${NAME} ${NAME})
  set_tests_properties(${NAME} PROPERTIES TIMEOUT ${TIMEOUT})
endmacro(setup_target)

add_executable(test_main tests/test_main.c tests/test_helper.h)
setup_target(test_main 5)

add_executable(test_stack tests/test_stack.c tests/test_helper.h)
setup_target(test_stack 5)

add_executable(test_windshieldwiper tests/test_windshieldwiper.c tests/test_helper.h)
setup_target(test_windshieldwiper 5)
