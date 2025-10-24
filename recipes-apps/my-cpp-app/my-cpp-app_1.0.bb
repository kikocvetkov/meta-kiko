UMMARY = "My C++ Application for Raspberry Pi"
DESCRIPTION = "A custom C++ application built with CMake and systemd integration"
LICENSE = "CLOSED"

SRC_URI = " \
    file://CMakeLists.txt \
    file://main.cpp \
    file://my-cpp-app.service \
"

S = "${WORKDIR}"

DEPENDS = "systemd"

inherit cmake systemd

SYSTEMD_SERVICE:${PN} = "my-cpp-app.service"
SYSTEMD_AUTO_ENABLE = "enable"

do_install:append() {
    # Install systemd service file (CMake handles the binary installation)
    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${S}/my-cpp-app.service ${D}${systemd_system_unitdir}
}

FILES:${PN} += "${systemd_system_unitdir}"