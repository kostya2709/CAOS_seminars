all:
	@gcc -fPIC -c dynamic_lib.c -o dynamic.o
	@gcc -shared -o libdynamic.so dynamic.o
	@export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.
	@gcc main.c -L. -ldynamic
	@./a.out
