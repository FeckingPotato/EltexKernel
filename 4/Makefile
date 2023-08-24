KMOD_NAME = eltexLedMod
obj-m += $(KMOD_NAME).o
all: kmod

kmod: dir
	cp $(KMOD_NAME).c objdir
	cp Makefile objdir
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD)/objdir modules
	cp objdir/$(KMOD_NAME).ko build

dir:
	mkdir -p objdir build

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/objdir clean
	rm -rf objdir build

clion_comp:
	cc -I/usr/lib/modules/6.4.9-zen1-1-zen/build/include/ eltexLedMod.c