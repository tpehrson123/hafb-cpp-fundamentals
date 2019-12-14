set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

set(TARGET_NAME ca)      # program name
# 
# Note: In windows, the executable name will be: ca.exe
add_executable(${TARGET_NAME} main.cpp)