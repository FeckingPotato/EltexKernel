KMOD_NAME = eltexChardevMod
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
