;
; Largest-Number.asm
;
; Created: 21-09-2024 19:19:00
; Author : Prakash Kushwaha
;


.ORG 0x00
LDI R20, 0x9			; Load immediate 0x5 into r20
LDI XL, 0x70			; Load immediate 0x70 into XL
LDI XH, 0x00			; Load immediate 0x00 into XH

LD R16, X				; Maximum Number
LD R17, X+				; Minimum Number

LOOP:
LD R18, X+				; Load value from memory into r16, post increment X
CP R18, R16				; Compare r18 with r16
BRCS MINIMUM			; If carry flag is set then branch to MINIMUM
MOV R16, R18			; Copies content of r18 to r16

MINIMUM: CP R17, R18	; Compare r18 with r17
BRCS SKIP				; If carry flag is set then branch to SKIP
MOV R17, R18			; Copies content of r18 to r17

SKIP: DEC R20			; Decrement r20 by 1
BRNE LOOP				; Exit from the loop when r16 contains 0

OUT PORTA, R16			; Output r16 to PORTA
OUT PORTB, R17			; Output r17 to PORTB
BREAK
