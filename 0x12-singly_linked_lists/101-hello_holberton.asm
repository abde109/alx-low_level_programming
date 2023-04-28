section .data
    hello db 'Hello, Holberton', 0

section .text
    global main
    extern printf

main:
    ; prepare the arguments for printf
    mov rdi, hello ; the format, %s
    xor rax, rax   ; because printf is a variadic function

    ; call printf
    call printf

    ; return from main
    mov eax, 60 ; the syscall number for sys_exit
    xor rdi, rdi ; exit code 0
    syscall ; call the kernel

