cmake_minimum_required(VERSION 2.6)
add_executable( stepanov_example
main.cpp
rotate/rotate.h
)

target_include_directories(stepanov_example
  PUBLIC 
  ../../catch2/)