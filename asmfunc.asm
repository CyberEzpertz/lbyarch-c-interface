section .data
multiplier dq 255.0

section .text
bits 64
default rel

global imgCvtGrayFloatToInt

imgCvtGrayFloatToInt:
	; count goes to rcx
	; pointer to double array goes to rdx
	; pointer to uint8_t array goes to r8

	xor rbx, rbx
	movsd xmm1, [multiplier]

START:
	movsd xmm0, [rdx + rbx * 8]

	mulsd xmm0, xmm1
	cvtsd2si rsi, xmm0

	mov byte [r8 + rbx], sil

	inc rbx

	cmp rbx, rcx
	jl START


ret