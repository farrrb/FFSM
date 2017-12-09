cmake_minimum_required(VERSION 3.2)
project(fbpfsm_root)

# enable code coverage
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/externals/cmake-codecov/cmake" ${CMAKE_MODULE_PATH})
message(${CMAKE_MODULE_PATH})
find_package(codecov)

add_subdirectory(externals)

add_subdirectory(source)

enable_testing()

set(NAME test_main)
set(TIMEOUT 5)

add_executable(${NAME} tests/${NAME}.c)
add_coverage(${NAME})
target_include_directories(${NAME} PRIVATE source)
target_link_libraries(${NAME} fbpfsm)
add_test(${NAME} ${NAME})
set_tests_properties(${NAME} PROPERTIES TIMEOUT ${TIMEOUT})
