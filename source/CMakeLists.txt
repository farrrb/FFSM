cmake_minimum_required(VERSION 3.2)
project(FFSM C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
  FFSM.c
  FFSM.h
  FFSM_Strings.c
  FFSM_Strings.h
  FFSM_Stack.c FFSM_Stack.h)

add_library(FFSM ${SOURCE_FILES})
add_coverage(FFSM)
