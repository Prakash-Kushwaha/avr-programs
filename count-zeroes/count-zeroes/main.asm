;
; count-zeroes.asm
;
; Created: 19-10-2024 22:26:37
; Author : Prakash Kushwaha
;


; Registers
.DEF NUM =R16		; 8-bit Number
.DEF COUNTER =R17	; Counter
.DEF ZEROES =R18	; Zeroes Count

LDI NUM, 0b11011010	; 8-bit number
LDI COUNTER, 0x8	; Counter
SEC					; Set Carry Flag
	
LOOP:
	ROR NUM			; Rotate Right Through Carry
	BRCS SKIP		; Branch to SKIP if Carry is Set
	INC ZEROES		; Add 1 to Zeroes Register count

SKIP:
	DEC COUNTER		; Decrement the counter by 1
	BREQ END		; Jump to END if Zero Flag is set
	RJMP LOOP		; Jump to Loop

END:
	BREAK			; Halts the program