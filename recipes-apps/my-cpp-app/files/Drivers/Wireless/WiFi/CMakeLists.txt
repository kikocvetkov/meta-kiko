SET(WIFI_SRC
    Wifi.cpp
)

add_library(wifi_library STATIC ${WIFI_SRC})

pkg_check_modules(SDBUS REQUIRED IMPORTED_TARGET sdbus-c++)

target_include_directories(wifi_library PUBLIC
 ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(wifi_library
     PkgConfig::SDBUS
)
