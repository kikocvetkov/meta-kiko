SUMMARY = "My C++ Application for Raspberry Pi"
DESCRIPTION = "A custom C++ application built with CMake and systemd integration"
LICENSE = "CLOSED"

SRC_URI = " \
    file://CMakeLists.txt \
    file://main.cpp \
    file://Hal/ \
    file://my-cpp-app.service \
    file://Objects.hpp \
    file://Os/  \
    file://Tasks/ \
    file://Drivers/ \
"

S = "${WORKDIR}"

DEPENDS = "systemd pkgconfig-native libgpiod rpi-gpio raspi-gpio sdbus-c++" 

inherit cmake systemd

SYSTEMD_SERVICE:${PN} = "my-cpp-app.service"
SYSTEMD_AUTO_ENABLE = "enable"

do_compile[nostamp] = "1"
do_install[nostamp] = "1"

do_install:append() {
    # Install systemd service file (CMake handles the binary installation)
    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${S}/my-cpp-app.service ${D}${systemd_system_unitdir}
}

FILES:${PN} += "${systemd_system_unitdir}"
