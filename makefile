
.PHONY: all build clean test

all: build

build:
	meson setup builddir
	cd builddir && ninja

clean:
	rm -rf builddir

test:
	meson test -C builddir
