cmake_minimum_required(VERSION 3.10)
project(MyCppApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(PkgConfig REQUIRED)

add_subdirectory("Hal")
add_subdirectory("Os")

# Add executable
add_executable(my-cpp-app
 main.cpp
 Tasks/BleTask.cpp
 )

# Link libraries
target_link_libraries(my-cpp-app
 hal_library
 os_library
 )

# Install target
install(TARGETS my-cpp-app DESTINATION ${CMAKE_INSTALL_BINDIR})
