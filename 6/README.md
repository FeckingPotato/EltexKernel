# Description

Kernel module: creates a netlink socket which logs received messages and replies to them with "Hello from kernel"

Userspace program: sends "Hello" message to the netlink socket and prints a reply

NOTE: the original code does not include the `unistd.h` header in the userspace program which is required for
`get_pid()` and `close()`

# Makefile targets

- all - builds kmod and user
- user - builds the userspace program
- kmod - builds the module and copies the .ko file to the build directory
- dir - creates working directories
- clean - removes working directories

# Working directories

- objdir - temporary object files
- build - ready to use files

# Example usage

![1.png](img%2F1.png)