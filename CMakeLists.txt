cmake_minimum_required(VERSION 3.29)
project(Labs1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labs1 main.cpp
        Task.cpp
        Task.h
        Problem.cpp
        Problem.h
        Solution.cpp
        Solution.h
        heur.cpp
        heur.h)
