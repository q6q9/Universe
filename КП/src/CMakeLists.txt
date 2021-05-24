cmake_minimum_required(VERSION 3.19)
project(end_copy)

set(CMAKE_CXX_STANDARD 17)

add_executable(end_copy main.cpp Cinema.h Cinema.cpp  Film.h Film.cpp Repertoire.h Repertoire.cpp funcs.cpp funcs.h Output.h Output.cpp)

