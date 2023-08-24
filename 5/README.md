# Description

Creates an unwritable chardev which reports how many times it has been read.

NOTE: starting from some linux kernel version (probably 6.4), the `class_create` function only requires the device name
[(commit)](https://github.com/torvalds/linux/commit/1aaba11da9aa7d7d6b52a74d45b31cac118295a1)

Removing `THIS_MODULE` from the function call at the 54th line fixes the issue 

# Makefile targets

- all - builds kmod
- kmod - builds the module and copies the .ko file to the build directory
- dir - creates working directories
- clean - removes working directories

# Working directories

- objdir - temporary object files
- build - ready to use files

# Example usage

![1.png](img%2F1.png)