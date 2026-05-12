SUMMARY = "Simple calculator application with Makefile and system d features"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://calculator.cpp \
           file://Makefile \
           file://calculator.service"
S = "${UNPACKDIR}"

inherit systemd

SYSTEMD_SERVICE:${PN} = "calculator.service"
SYSTEMD_AUTO_ENABLE = "enable"

do_compile(){
	oe_runmake
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 mycal ${D}${bindir}

    install -d ${D}${systemd_system_unitdir}

    install -m 0644 calculator.service \
        ${D}${systemd_system_unitdir}/calculator.service
}