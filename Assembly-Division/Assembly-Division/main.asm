;
; Assembly-Division.asm
;
; Created: 21-09-2024 17:53:16
; Author : Prakash Kushwaha
;

.ORG 0x00

.DEF Dividend =R16			; Dividend
.DEF Divisor =R17			; Divisor
.DEF Quotient =R18			; Quotient
.DEF Remainder =R19			; Remainder

LDI Dividend, 0x8			; Load immediate 0x8 into r16
MOV Remainder, Dividend		; Copies r17 content t r19
LDI Divisor, 0x3			; Load immediate 0x3 into r17

LOOP: CP Remainder, Divisor	; Compare r19 and r17
	BRCS NXT				; Branch to RESULT if A < B
	SUB Remainder, Divisor	; Subtract Divisor from Remainder
	INC Quotient			; Increment Quotient by 1
	RJMP LOOP				; Jump back to LOOP

RESULT: OUT PORTA, Quotient	; Output r18 to PORTA
	OUT PORTB, Remainder	; Output r19 to PORTB
	BREAK
