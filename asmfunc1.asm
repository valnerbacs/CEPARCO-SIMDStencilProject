;Bacayan, Vincent Alner J.

section .text
bits 64
default rel
global calculateYx86

;rcx - 1st param - ARRAY_BYTES, rdx - 2nd param - X, r8 - 3rd param - Y

calculateYx86:
    push rbp
    mov rbp, rsp
    sub rsp, 16                 ; copy paste portion

    mov r12, rcx                ; use rcx as i and r12 as basis, rcx contains ARRAY_BYTES so mov to r12
    sub r12, 6                  ; loop condition is i < ARRAY_BYTES - 6,
    mov r13, rdx                
    mov r14, r8                
    xor rcx, rcx                ; Initialize loop counter

loop_start:
    cmp rcx, r12                ; Loop condition,if i < ARRAY_BYTES -6 then loop
    jge loop_end                

    mov rax, QWORD [r13 + rcx * 8]          ;load X[i]
    add rax, QWORD [r13 + rcx * 8 + 8]      ;X[i+i]
    add rax, QWORD [r13 + rcx * 8 + 16]
    add rax, QWORD [r13 + rcx * 8 + 24]
    add rax, QWORD [r13 + rcx * 8 + 32]
    add rax, QWORD [r13 + rcx * 8 + 40]
    add rax, QWORD [r13 + rcx * 8 + 48]     ;X[i+6]

    mov QWORD [r14 + rcx * 8], rax          ; store ans to Y

    inc rcx              ; i++
    jmp loop_start              ; check condition again

loop_end:
    leave                       ; NOTE: supposed to be pop rbp, but it doesn't work somehow and this does
    ret                         