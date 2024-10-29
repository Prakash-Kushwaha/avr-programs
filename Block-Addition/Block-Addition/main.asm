;
; Block-Addition.asm
;
; Created: 21-09-2024 12:45:55
; Author : Prakash Kushwaha
;


.ORG 0x00
LDI R20, 0x5		; Load immediate 0x5 into r20
LDI R16, 0x0		; Load immediate 0x0 into r16
LDI XL, 0x70		; Load immediate 0x70 into XL
LDI XH, 0x00		; Load immediate 0x00 into XH
LDI YL, 0x90		; Load immediate 0x90 into YL
LDI YH, 0x00		; Load immediate 0x00 into YH

LOOP:
LD R17, X+			; Load value from memory into r16, post increment X
ADD R16, R17
DEC R20				; Decrement r20 by 1
BRNE LOOP			; Exit from the loop when r16 contains 0

ST Y, R16			; Store r16 into memory
BREAK
