; Group 4 Members: Joshua Benedict B. Co & Llandro Massimo B. Colcol
; Course & Section: LBYARCH | S12A

; Assembly function implementation of SAXPY (Single-Precision A*X Plus Y)


section .text
bits 64
default rel

global saxpy_asm_group4


saxpy_asm_group4:
    ; Function parameters:
    ; xmm0 = float A (scalar multiplier)
    ; rdx  = float* X
    ; r8   = float* Y
    ; r9   = float* Z
    ; [rbp + 32] = int n (5th argument passed via stack)

    PUSH    rbp                      ; Preserve base pointer
    PUSH    rbx                      ; Preserve rbx (callee-saved)
    MOV     rbp, rsp                 
    ADD     rbp, 16                  ; Skip saved rbp and rbx
    ADD     rbp, 8                   ; Adjust for stack alignment

    MOV     r11, [rbp + 32]          ; Move loop counter n into r11
    MOVSS   xmm2, xmm0               ; Copy scalar A into xmm2 for reuse

next:
    TEST    r11, r11                 ; Check if loop counter is zero
    JZ      done                     ; Exit loop if done

    MOVSS   xmm3, [rdx]              ; Load X[i] into xmm3
    MULSS   xmm3, xmm2               ; Multiply A * X[i]
    ADDSS   xmm3, [r8]               ; Add Y[i] to result
    MOVSS   [r9], xmm3               ; Store result to Z[i]

    ADD     rdx, 4                   ; Advance X pointer
    ADD     r8, 4                    ; Advance Y pointer
    ADD     r9, 4                    ; Advance Z pointer

    DEC     r11                      ; Decrement counter
    JMP     next                     ; Continue loop

done:
    POP     rbx                      ; Restore rbx
    POP     rbp                      ; Restore base pointer
    RET