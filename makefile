.PHONY: all build install clean

all: clean build install

build:
	meson setup builddir
	meson compile -C builddir

test:
	meson setup testdir
	meson test -C builddir

install:
	cd builddir && ninja install

clean:
	rm -rf builddir
	rm -rf temp
