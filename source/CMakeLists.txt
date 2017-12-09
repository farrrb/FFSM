cmake_minimum_required(VERSION 3.2)
project(fbpfsm C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES FFSM.c FFSM_Strings.c)

add_library(fbpfsm ${SOURCE_FILES})
add_coverage(fbpfsm)
