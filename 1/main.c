#include <stdio.h>

#if DL == 1
#include <dlfcn.h>
#else
#include "libmath.h"
#endif

int main(int argc, char *argv[]) {
#if DL == 1
	void *handle;
	if (argc == 1) {
		handle = dlopen("./libmath.so", RTLD_LAZY);
	}
	else {
		handle = dlopen(argv[1], RTLD_LAZY);
	}
	if (!handle) {
		fputs(dlerror(), stderr);
		return 1;
	}
	int (*mul)(int, int)  = dlsym(handle, "mul");
	int (*div)(int, int)  = dlsym(handle, "div");
#endif
	int a, b;
	printf("First number: ");
	scanf("%d", &a);
	printf("Second number: ");
	scanf("%d", &b);
	printf("Mul: %d\n", mul(a, b));
	printf("Div: %d\n", div(a, b));
	return 0;
}
