#!/bin/sh
# PicoDrive for Koriki (Miyoo Mini): generic SDL 1.2 platform, Mini keys
# (platform/koriki/inputmap.c). Koriki's SDL stretches any video mode to
# the whole screen with MI_GFX, so the picture is scaled by hardware.
set -e
TC=${TC:-/opt/miyoomini-toolchain}
export PATH=$TC/bin:$PATH
CROSS_COMPILE=arm-linux-gnueabihf- \
CFLAGS="-marm -mcpu=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard -D__KORIKI__" \
	./configure --platform=generic --sound-drivers=sdl --with-sdl-gles=no
make use_inputmap=koriki "$@"
