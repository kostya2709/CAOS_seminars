
clean:
	@rm prog
	@rm prog sym_table a.out *.o *.a *dump
	@rm sym_table

build:
	@g++ main.cpp lib.cpp -o prog

all: build
	@./prog

sym_table: all
	@objdump -t prog > sym_table

static_lib:
	@g++ -c lib.cpp -o lib.o
	@ar rc libSTATIC_LIB.a lib.o
	@g++ main.cpp libSTATIC_LIB.a
#	@g++ main.cpp -L. -lSTATIC_LIB
	@./a.out
	
dump:
	@g++ -c main.cpp -o main.o
	@objdump -d -M intel main.o > main_dump
	@make build
	@objdump -d -M intel prog > all_dump
