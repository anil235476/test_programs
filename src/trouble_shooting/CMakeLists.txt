cmake_minimum_required(VERSION 2.6)
add_executable( trouble_shooting
main.cpp

)

target_include_directories(trouble_shooting
  PUBLIC 
  ../../catch2/)