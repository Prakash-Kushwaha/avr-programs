;
; tap-sensor.asm
;
; Created: 21-10-2024 21:39:36
; Author : Prakash Kushwaha
;


CBI DDRB, 1			; Making Bit-1 of PORTB as Input
SBI DDRC, 7			; Making Bit-7 of PORTC as Output

LOOP:
	IN R16, PINB	; Reading the input data from the sensor
	BREQ ACTIVATED	; branch if data is LOW
	CBI PORTC, 7	; Clears the Bit-7 of PORTC
	RJMP LOOP		; Jump to the LOOP

ACTIVATED:
	SBI PORTC, 7	; Sets the Bit-7 of PORTC
	RJMP LOOP		; Jump to the LOOP
