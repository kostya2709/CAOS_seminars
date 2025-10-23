intr:
	gcc -mavx intrinsics.c

call_printf:
	gcc -g -no-pie call_printf.S

sum:
	gcc -O3 sum.c sum.S

write:
	nasm -f elf64 write.asm
	ld write.o

clean:
	rm *.out
