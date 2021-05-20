cmake_minimum_required(VERSION 3.19)
project(end_copy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(end_copy
        Cinema.cpp
        Cinema.h
        Film.cpp
        Film.h
        funcs.cpp
        funcs.h
        main.cpp
        Output.cpp
        Output.h
        Repertoire.cpp
        Repertoire.h)
