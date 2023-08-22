# Description

Creates a file in /proc which allows writing and reading

The original source code had to be fixed to make it work with new kernel versions

![1.png](img%2F1.png)

# Makefile targets

- all - builds kmod
- kmod - builds the module and copies the .ko file to the build directory
- dir - creates working directories
- clean - removes working directories

# Working directories

- objdir - temporary object files
- build - ready to use files

# Example usage

![2.png](img%2F2.png)