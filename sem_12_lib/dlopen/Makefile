all: build_dyn_lib
	@export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.
	@gcc -ldl main.c
	@./a.out

build_dyn_lib:
	@gcc -fPIC -c dynamic_lib.c -o dynamic.o
	@gcc -shared -o libdynamic.so dynamic.o
