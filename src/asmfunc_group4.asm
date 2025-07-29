; Group 4 Members: Joshua Benedict B. Co & Llandro Massimo B. Colcol
; Course & Section: LBYARCH | S12A

; Assembly function implementation of SAXPY (Single-Precision A*X Plus Y)


section .text
bits 64
default rel

global saxpy_asm_group4

saxpy_asm_group4:
    ; Parameters:
    ; rcx  = int n
    ; xmm0 = float A
    ; rdx  = float *X
    ; r8   = float *Y
    ; r9   = float *Z

    XOR r10, r10                  ; i = 0
    MOVSS xmm1, xmm0              ; xmm1 = A


.loop:
    CMP r10, rcx                  ; if i >= n, break
    JGE .done

    MOVSS   xmm2, [rdx + r10*4]   ; xmm2 = X[i]
    MULSS   xmm2, xmm1            ; xmm2 *= A
    ADDSS   xmm2, [r8 + r10*4]    ; xmm2 += Y[i]
    MOVSS   [r9 + r10*4], xmm2    ; Z[i] = result

    INC r10
    JMP .loop


.done:
    RET
