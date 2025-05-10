cmake_minimum_required(VERSION 3.28)
project(Lab_6_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_6_1 main.cpp
        password_errors.cpp
        password_errors.h
        password_checker.cpp
        password_checker.h)
