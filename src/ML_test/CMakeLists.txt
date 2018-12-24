cmake_minimum_required(VERSION 2.6)
add_executable( ML_test
main.cpp
ml_test.h

)

target_include_directories(ML_test
  PUBLIC 
  ../../catch2/)