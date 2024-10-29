;
; multiply-signed.asm
;
; Created: 12-09-2024 21:04:51
; Author : Prakash Kushwaha
;


.ORG 0x00
LDI R20, 0xf5		; Load immediate 0xF5 into r20
LDI R21, 0xf3		; Load immediate 0xF3 into r21
MULS R20, R21		; Multiply r20 to r21, result in r0 and r1
OUT PORTA, R0		; Output R0 to PORTA
OUT PORTB, R1		; Output R1 to PORTB
BREAK
