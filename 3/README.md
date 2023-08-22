# Description

Creates a file in /sys which allows writing and reading

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