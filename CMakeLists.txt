cmake_minimum_required(VERSION 3.2)
project(fbpfsm_root)

# Enable code coverage
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/externals/CMake-codecov/cmake" ${CMAKE_MODULE_PATH})
find_package(codecov)

# CTest
enable_testing()

add_subdirectory(externals)
add_subdirectory(source)

set(NAME test_main)
set(TIMEOUT 5)

add_executable(${NAME} tests/${NAME}.c)
add_coverage(${NAME})
target_include_directories(${NAME} PRIVATE source externals/Unity/src)
target_link_libraries(${NAME} fbpfsm Unity)
add_test(${NAME} ${NAME})
set_tests_properties(${NAME} PROPERTIES TIMEOUT ${TIMEOUT})
