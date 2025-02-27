# Copyright 2019-2023 NXP
#
# PFE common recipe for Master/Slave

inherit module

SUMMARY = "Linux driver for the Packet Forwarding Engine hardware"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://LICENSE-GPL2.txt;md5=5dcdfe25f21119aa5435eab9d0256af7"

URL ?= "git://github.com/nxp-auto-linux/pfeng;protocol=https;nobranch=1"
SRC_URI = "${URL}"

SRCREV ?= "453c5b5d98415a68db5e486c2e52261fcba1388a"

S = "${WORKDIR}/git"
MDIR = "${S}/sw/linux-pfeng"
INSTALL_DIR = "${D}/${base_libdir}/modules/${KERNEL_VERSION}/kernel/drivers/net/ethernet/nxp/pfe"

EXTRA_OEMAKE:append = " KERNELDIR=${STAGING_KERNEL_DIR} MDIR=${MDIR} -C ${MDIR} V=1 drv-build"

COMPATIBLE_MACHINE = "s32g"
