CROSS_COMPILE?=/root/armv7l-tizen/bin/armv7l-tizen-linux-gnueabi-

.PHONY: audio_track_rotator
audio_track_rotator:
	$(CROSS_COMPILE)g++ -I${KDIR} -std=c++11 `pkg-config --cflags --libs glib-2.0` -L../tizen_libs $(@).cpp -Wl,--unresolved-symbols=ignore-in-shared-libs -ldl -ltvs-api -o $(@)