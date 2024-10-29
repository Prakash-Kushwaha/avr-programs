;
; multiplication.asm
;
; Created: 08-09-2024 11:46:26
; Author : Prakash Kushwaha
;


.ORG 0x00
LDI R20,0x3			; Load immediate 0x3 into r20
LDI R21, 0x2		; Load immediate 0x2 into r21
MUL R20, R21		; Multiply r20 to r21, result in r0 and r1
OUT PORTA, R0		; Output R0 to PORTA
OUT PORTB, R1		; Output R1 to PORTB
BREAK
