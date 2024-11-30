section .data
multiplier dq 255.0

section .text
bits 64
default rel

global imgCvtGrayFloatToInt

imgCvtGrayFloatToInt:
	; count goes to rcx

	xor rbx, rbx
	

START:
	
	movsd xmm0, [rdx + rbx * 8]
	movsd xmm1, [multiplier]

	mulsd xmm0, xmm1
	cvtsd2si rsi, xmm0

	mov dword [r8 + rbx * 4], esi

	inc rbx

	LOOP START
ret