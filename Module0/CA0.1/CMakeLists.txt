# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(CA0.1 LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(message 
  STATIC
    helloWorld.hpp
    helloWorld.cpp
  )

# main code
add_executable(hello main.cpp)
target_link_libraries(hello message) # Link Library

# # Prepare "Catch" library for other executables
# set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
# add_library(Catch INTERFACE)
# target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# This will create your testing file
add_executable(hello_test test.cpp)
# target_link_libraries(hello_test message Catch)
target_link_libraries(hello_test message)

# enable testing functionality
enable_testing()

# define test
add_test(
  NAME catch_test
  COMMAND $<TARGET_FILE:hello_test> --success
  )
