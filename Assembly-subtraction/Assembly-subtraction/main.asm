;
; Assembly-subtraction.asm
;
; Created: 21-09-2024 12:00:35
; Author : Prakash Kushwaha
;


.ORG 0x00
LDI R20, 0x8		; Load immediate Number1: 0x8 into r20
LDI R19, 0x5		; Load immediate Number2: 0x5 into r19
SUB R19, R20		; Subtract r20 from r19, result (Number1-Number2) in r19
OUT PORTA, R19		; Output Result: r19 to PORTA
BREAK
