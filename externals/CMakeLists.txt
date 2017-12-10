cmake_minimum_required(VERSION 3.2)
project(Unity C)
set(CMAKE_C_STANDARD 99)

add_library(Unity STATIC
  Unity/src/unity.c
  Unity/src/unity.h
  Unity/src/unity_internals.h
  )
target_include_directories(Unity PUBLIC Unity/src)