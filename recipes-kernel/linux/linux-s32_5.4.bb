require recipes-kernel/linux/linux-s32.inc

BRANCH ?= "${RELEASE_BASE}-${PV}-rt"
SRC_URI = "${URL};branch=${BRANCH}"
SRCREV = "223bfbe0d2c1ec1d1cd37cc4a2899bd6a4d1682d"

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

# Perf patches
SRC_URI += " \
    file://perf/0001-perf-cs-etm-Move-definition-of-traceid_list-global-v.patch \
"

# Enable 100MB BAR support for S32G and R
SRC_URI_append_gen1 += " ${@bb.utils.contains('DISTRO_FEATURES', 'pcie-large-bars', \
	'file://0001-s32gen1-Increase-reserved-mem-and-EP-BAR-2-to-100MB.patch', '', d)}"
