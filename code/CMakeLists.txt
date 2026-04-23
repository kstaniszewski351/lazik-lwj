cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(lazik CXX)

include(Findpigpio.txt)

add_executable(lazik
    src/main.cpp
    src/motor_driver.cpp
    src/controller_manager.cpp
    src/input_manager.cpp
    src/utils.cpp
)

#add_library(PIGPIO_LIB SHARED IMPORTED)
#find_library(PIGPIO_LIB libpigpio)
#find_package(pigpio REQUIRED)
find_package(SDL3 REQUIRED)

target_link_libraries(lazik PRIVATE
    "${pigpio_LIBRARY}"
    SDL3::SDL3
)

