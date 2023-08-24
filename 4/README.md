# Description

Makes keyboard LEDs blink

Creates `/sys/kbleds/control` file which allows controlling the blinking LEDs with a binary mask (e.g. 1(001) 2(010) 7(111))

# Makefile targets

- all - builds kmod
- kmod - builds the module and copies the .ko file to the build directory
- dir - creates working directories
- clean - removes working directories

# Working directories

- objdir - temporary object files
- build - ready to use files
