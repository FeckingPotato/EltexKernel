obj-m += eltexSysMod.o
all: kmod

kmod: dir
	cp eltexSysMod.c objdir
	cp Makefile objdir
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD)/objdir modules
	cp objdir/eltexSysMod.ko build

dir:
	mkdir -p objdir build

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/objdir clean
	rm -rf objdir build
