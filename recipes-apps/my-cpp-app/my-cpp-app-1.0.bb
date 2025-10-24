SUMMARY = "My C++ Application for Raspberry Pi"
DESCRIPTION = "A custom C++ application built with CMake and systemd integration"
LICENSE = "CLOSED"

SRC_URI = " \
    file://CMakeLists.txt \
    file://main.cpp \
    file://my-cpp-app.service \
"

DEPENDS = "systemd"

inherit cmake pkgconfig systemd

SYSTEMD_SERVICE:${PN} = "my-cpp-app.service \"
SYSTEMD_AUTO_ENABLE:${PN} = "enable"

do_install:append() {
    # Install binary
    install -d ${D}${bindir}
    install -m 0755 ${S}/build/my-cpp-app ${D}${bindir}
    
    # Install systemd service file
    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${S}/my-cpp-app.service ${D}${systemd_system_unitdir}/my-cpp-app.service
}

FILES:${PN} += " \
    ${bindir} \
    ${systemd_system_unitdir} \
    ${sysconfdir} \
"

# Dependencies for the application
RDEPENDS:${PN} += " \
    systemd \
"