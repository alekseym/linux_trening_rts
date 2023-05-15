cmake_minimum_required(VERSION 3.10)

project(hello
#  LANGUAGES CXX
  VERSION 1.0
)

#set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(hello main.cpp)

set_property(TARGET hello PROPERTY CXX_STANDARD 11)


