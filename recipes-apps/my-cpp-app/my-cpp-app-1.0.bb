SUMMARY = "My C++ Application for Raspberry Pi"
DESCRIPTION = "A custom C++ application built with CMake and systemd integration"
LICENSE = "CLOSED"

SRC_URI = " \
    files://CMakeLists.txt \
    files://main.cpp \
    files://my-cpp-app.service \
    files://my-cpp-app.conf \
"

DEPENDS = "systemd"

S = "${WORKDIR}"

inherit cmake pkgconfig systemd

SYSTEMD_SERVICE:${PN} = "my-cpp-app.service"
SYSTEMD_AUTO_ENABLE:${PN} = "enable"

do_install:append() {
    # Install binary
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/build/my-cpp-app ${D}${bindir}/
    
    # Install systemd service file
    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${S}/my-cpp-app.service ${D}${systemd_system_unitdir}/
    
    # Install configuration file
    install -d ${D}${sysconfdir}/my-cpp-app
    install -m 0644 ${S}/my-cpp-app.conf ${D}${sysconfdir}/my-cpp-app/

    # Create log directory (optional - systemd usually handles this)
    install -d ${D}${localstatedir}/log/my-cpp-app
}

FILES:${PN} += " \
    ${bindir}/my-cpp-app \
    ${systemd_system_unitdir}/my-cpp-app.service \
    ${sysconfdir}/my-cpp-app/my-cpp-app.conf \
    ${localstatedir}/log/my-cpp-app \
"

# Dependencies for the application
RDEPENDS:${PN} += "systemd"