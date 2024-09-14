
all:
	g++ -fsanitize=address main.cpp
	ASAN_OPTIONS=detect_stack_use_after_return=1 ./a.out
