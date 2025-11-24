SET(OS_SRC
    Thread.cpp
 )

add_library(os_library STATIC ${OS_SRC})

pkg_check_modules(SYSTEMD REQUIRED libsystemd)

target_include_directories(os_library PUBLIC
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${SYSTEMD_INCLUDE_DIRS}
 )

link_directories(${SYSTEMD_LIBRARIES_DIRS})
 
target_link_libraries(os_library
     systemd
)
