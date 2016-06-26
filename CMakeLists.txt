cmake_minimum_required(VERSION 3.5)
project(snake)
#set(CMAKE_C_FLAGS_DEBUG -lgraph)
#set(CMAKE_CXX_FLAGS_DEBUG  -lgraph)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGL -lglut")
set(SOURCE_FILES main.cpp include.h)

add_executable(snake ${SOURCE_FILES} )