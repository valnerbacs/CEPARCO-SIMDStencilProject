section .text
bits 64
default rel
global calculateYSIMD

;rcx - 1st param - ARRAY_SIZE, rdx - 2nd param - X, r8 - 3rd param - Y

calculateYSIMD:
    push rbp
    mov rbp, rsp
    sub rsp, 16                 ; copy paste portion

    mov r12, rcx                ; use rcx as i and r12 as basis, rcx contains ARRAY_SIZE so move to r12
    sub r12, 16                 ; loop condition is i < ARRAY_SIZE - 16, because we process 8 elements per iteration
    mov r13, rdx                
    mov r14, r8                
    xor rcx, rcx                ; Initialize loop counter

loop_start:
    cmp rcx, r12                ; Loop condition, if i < ARRAY_SIZE - 16 then loop
    jge loop_end

    vmovdqu ymm0, [r13 + rcx * 8]                   ; load 8 elements from X
    

loop_end:
    leave                                           ; NOTE: supposed to be pop rbp, but it doesn't work somehow and this does
    ret