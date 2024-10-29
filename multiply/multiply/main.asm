;
; multiply.asm
;
; Created: 05-09-2024 19:44:23
; Author : Prakash Kushwaha
;

start:
	LDI R20, 0x3
	LDI R21, 0x4
	MUL R3, R4
	OUT PORTB, R1
	OUT PORTC, R2
end: