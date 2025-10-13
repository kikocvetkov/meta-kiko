cmake_minimum_required(VERSION 3.10)
project(MyCppApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(SYSTEMD REQUIRED libsystemd)

# Add executable
add_executable(my-cpp-app my-cpp-app.cpp)

# Include directories
include_directories(${SYSTEMD_INCLUDE_DIRS})

# Link libraries
target_link_libraries(my-cpp-app ${SYSTEMD_LIBRARIES})

# Install target
install(TARGETS my-cpp-app DESTINATION bin)