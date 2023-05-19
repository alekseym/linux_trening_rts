cmake_minimum_required (VERSION 3.5)
project(cloud-installer)

include(FetchContent)

set (BUILD_DPS ON CACHE INTERNAL "")
set (BUILD_EXAMPLES OFF CACHE INTERNAL "")

FetchContent_Declare(
    up2date-cpp
    GIT_REPOSITORY  https://github.com/rtsoft-gmbh/up2date-cpp.git
    GIT_TAG         v2.2.0
)

FetchContent_MakeAvailable(up2date-cpp)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
        sub::ddi
        sub::dps
)
