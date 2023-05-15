cmake_minimum_required(VERSION 3.10)

project(hello
  LANGUAGES CXX
  VERSION 1.0
)

add_library(detect detector.cpp)
add_library(sender sender.cpp)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(hello main_old.cpp)

target_link_libraries(hello detect sender)
