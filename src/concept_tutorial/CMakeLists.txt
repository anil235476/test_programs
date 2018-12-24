cmake_minimum_required(VERSION 3.5)

add_compile_options("-fconcepts")
add_executable(concept_tut 
buffer.h
 main.cpp
)


target_compile_features(concept_tut PRIVATE cxx_std_17)
