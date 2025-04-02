cmake_minimum_required(VERSION 3.29)
project(spd1)

set(CMAKE_CXX_STANDARD 20)

add_executable(spd1 main.cpp
        Task.cpp
        Task.h
        Problem.cpp
        Problem.h
        Solution.cpp
        Solution.h
        Heur.h
        Heur.cpp
        algorithms.cpp
        algorithms.h
        utils.cpp
        utils.h)
