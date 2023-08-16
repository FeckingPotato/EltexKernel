run: all
	@echo ""
	@echo "Compiled with static library:"
	./build/main_static
	@echo ""
	@echo "Compiled with shared library:"
	LD_LIBRARY_PATH=build ./build/main_shared
	@echo ""
	@echo "Compuled with dynamically loaded shared library:"
	./build/main_shared_dyn ./build/libmath.so

all: main_static main_shared main_shared_dyn

main_static: libmath.a
	cc -c main.c -o objdir/main.o
	cc -o build/main_static objdir/main.o -L. build/libmath.a

main_shared: libmath.so
	cc -c main.c -o objdir/main.o
	cc -o build/main_shared objdir/main.o -lmath -Lbuild

main_shared_dyn: libmath.so
	cc -c main.c -DDL=1 -o objdir/main_dyn.o
	cc -o build/main_shared_dyn objdir/main_dyn.o -rdynamic

libmath.a: dir libmath.c libmath.h
	cc -c libmath.c -o objdir/libmathst.o
	ar rcs build/libmath.a objdir/libmathst.o

libmath.so: dir libmath.c libmath.h
	cc -c libmath.c -fpic -o objdir/libmathsh.o
	cc -shared -o build/libmath.so objdir/libmathsh.o

dir:
	mkdir -p objdir build

clean:
	rm -rf objdir build
