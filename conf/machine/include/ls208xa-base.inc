# Provides the common settings for LS208xA

require conf/machine/include/qoriq-atf.inc
require conf/machine/include/soc-family.inc

SOC_FAMILY = "fsl-lsch3:ls2:ls208xa"

IMAGE_FSTYPES = "tar.gz ext4"

# required for sdcard deploy
HOSTTOOLS += "parted mkfs.vfat mcopy udevadm"

EXTRA_IMAGECMD:ext4 = "-i 4096 -L ${IMAGE_NAME}"

EXTRA_IMAGEDEPENDS += "mc-utils management-complex ppa"

URL_MIGRATEFROM = "source.codeaurora.org/external/qoriq/qoriq-components"
URL_MIGRATETO = "github.com/nxp-qoriq"
INHERIT += "fsl-github-migrate"
BB_DANGLINGAPPENDS_WARNONLY = "1"

# No better place for this if it should stay in the layer
PREFERRED_PROVIDER_jpeg ?= "libjpeg-turbo"
PREFERRED_PROVIDER_jpeg-native ?= "jpeg-native"

# For all other elements we use the SDK defaults
require conf/machine/include/qoriq-arm64.inc
require conf/machine/include/arm/arch-arm64.inc

DTB_LOAD = "0x90000000"
UBOOT_ENTRYPOINT = "0x80200000"

# We also want to permit SD card image generation.
# This sets up the defaults, just in case the image
# specifies an addition of "sdcard" to IMAGE_FSTYPES.
# Note that we can not boot U-Boot from SD Card on BB Classic
SDCARD_ROOTFS ?= "ext4"
UBOOT_SUFFIX_SDCARD ?= "${UBOOT_SUFFIX}"

# 64 MB boot partition
BOOT_SPACE ?= "65536"

# Deploy rootfs type for bluebox images
IMAGE_ROOTFS_DEP_EXT ?= "ext4"
