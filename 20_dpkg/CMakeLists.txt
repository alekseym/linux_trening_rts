cmake_minimum_required(VERSION 3.12)

project(hello
  LANGUAGES CXX
  VERSION 1.0
)

add_subdirectory(detector)
add_subdirectory(sender)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(hello main_old.cpp)

target_link_libraries(hello detect sender)

install(TARGETS ${PROJECT_NAME}
    EXPORT "${PROJECT_NAME}Targets"
    COMPONENT ${PROJECT_NAME}
    RUNTIME DESTINATION "/home/"
    LIBRARY DESTINATION "/home/"
    DESTINATION "/home/"
)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "AM") #required
INCLUDE(CPack)
