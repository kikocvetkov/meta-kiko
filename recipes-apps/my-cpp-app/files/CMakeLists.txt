cmake_minimum_required(VERSION 3.10)
project(MyCppApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(SYSTEMD REQUIRED libsystemd)

# Add executable
add_executable(my-cpp-app main.cpp)

# Include directories
target_include_directories(my-cpp-app PRIVATE ${SYSTEMD_INCLUDE_DIRS})

# Link libraries
target_link_libraries(my-cpp-app ${SYSTEMD_LIBRARIES})

# Install target
install(TARGETS my-cpp-app DESTINATION ${CMAKE_INSTALL_BINDIR})