;
; assignment-ques.asm
;
; Created: 21-10-2024 22:41:07
; Author : Prakash Kushwaha
;


LDI R20, 0x24
SEC
ROL R20
CLC
LSR R20
SEC
ASR R20
CLC
LSL R20
SEC
ROR R20
BREAK
