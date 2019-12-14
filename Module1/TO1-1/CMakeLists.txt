# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(PA1-1 LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a Static Library
# add_library(factor 
#   STATIC
#     factor.h
#     factor.cpp
#   )


# main code with ouput name: ca1
# Note: In windows, the executable name will be: ca1.exe
add_executable(pa11 main.cpp)

# target_link_libraries(pa11 factor) # Link Library