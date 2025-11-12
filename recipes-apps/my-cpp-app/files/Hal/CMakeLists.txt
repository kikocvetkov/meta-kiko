SET(HAL_SRC DigitalPin.cpp)

SET(HAL_HDR DigitalPin.hpp)

add_library(hal_library STATIC ${HAL_SRC})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GPIOD REQUIRED libgpiod)

target_include_directories(hal_library PUBLIC
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${GPIOD_INCLUDE_DIRS}
 )

link_directories(${GPIOD_LIBRARY_DIRS})

target_link_libraries(hal_library
${GPIOD_LIBRARIES}
)
