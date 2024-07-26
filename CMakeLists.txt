cmake_minimum_required(VERSION 3.3)

project(bin) #имя проекта

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE main.cpp source/Vector.cpp)

add_executable(bin ${SOURCE})



