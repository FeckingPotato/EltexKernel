obj-m += eltexProcMod.o
all: kmod

kmod: dir
	cp eltexProcMod.c objdir
	cp Makefile objdir
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD)/objdir modules
	cp objdir/eltexProcMod.ko build

dir:
	mkdir -p objdir build

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/objdir clean
	rm -rf objdir build