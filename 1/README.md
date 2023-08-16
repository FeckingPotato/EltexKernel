# Description

The program asks user to input 2 numbers (A and B) and outputs the multiplication (A * B) and division results (A / B)

# Makefile targets

- run (default) - builds and runs all 3 versions of the program
- all - builds all 3 versions of the program
- main_static - builds the static lib version
- main_shared - builds the shared lib version
- main_shared_dyn - builds the shared lib version with dynamic loading
- libmath.a - builds the static library
- libmath.so - builds the shared library
- dir - creates working directories
- clean - removes working directories

# Working directories

- objdir - temporary object files
- build - ready to use files
