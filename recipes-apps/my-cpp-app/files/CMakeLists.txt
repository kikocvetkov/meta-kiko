cmake_minimum_required(VERSION 3.10)
project(MyCppApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
pkg_check_modules(SYSTEMD REQUIRED libsystemd)

add_subdirectory("Hal")

# Add executable
add_executable(my-cpp-app main.cpp)

# Include directories
<<<<<<< Updated upstream
include_directories(${SYSTEMD_INCLUDE_DIRS})
=======
target_include_directories(my-cpp-app PRIVATE
 ${SYSTEMD_INCLUDE_DIRS}
 )
>>>>>>> Stashed changes

# Link libraries
target_link_libraries(my-cpp-app
 ${SYSTEMD_LIBRARIES}
 hal_library
 )

# Install target
install(TARGETS my-cpp-app DESTINATION bin)