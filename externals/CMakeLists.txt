cmake_minimum_required(VERSION 3.2)
project(Unity)

add_library(Unity STATIC Unity/src/unity.c)
target_include_directories(Unity PUBLIC Unity/src)