section .data
    hello:     db 'Hello, World!', 0x0A
    hello_len: equ $ - hello
    
    SYS_WRITE: equ 1
    SYS_EXIT:  equ 60
    
    STDOUT:    equ 1

section .text
    global _start

_start:
    ; write(STDOUT, hello, hello_len)
    mov rax, SYS_WRITE
    mov rdi, STDOUT
    mov rsi, hello
    mov rdx, hello_len
    syscall

    ; exit(0)
    mov rax, SYS_EXIT
    mov rdi, 0
    syscall
