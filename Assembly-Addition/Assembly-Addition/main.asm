;
; Assembly-Addition.asm
;
; Created: 05-09-2024 16:29:23
; Author : Prakash Kushwaha
;

.ORG 0x00
LDI R20, 0xAD		; Load immediate Number1: 0x10 into r20
LDI R21, 0xBC		; Load immediate Number2: 0x34 into r21
ADD R20, R21		; Add r21 to r20, result in r20
OUT PORTA, R20		; Output r20 to PORTB
BREAK
