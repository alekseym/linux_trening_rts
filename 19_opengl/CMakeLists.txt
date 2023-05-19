cmake_minimum_required(VERSION 3.10)

project(hello
#  LANGUAGES CXX
  VERSION 1.0
)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

#add_executable(main test1.cpp)


include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

#set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(hello test1.cpp)

target_link_libraries(hello PUBLIC OpenGL::GL GLEW::GLEW glfw)

#target_link_libraries(hello ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

set_property(TARGET hello PROPERTY CXX_STANDARD 11)




