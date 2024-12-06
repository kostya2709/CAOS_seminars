all:
	@gcc -Wall -fPIC -shared -o libmalloc.so libmalloc2.c -ldl
	@gcc -o call_malloc call_malloc.c

hack:
	@LD_PRELOAD=./libmalloc.so ./call_malloc
