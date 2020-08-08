	.arch msp430g2553
	.palign 1,0


	.data
state:	.byte 0


	.text
jt:
	.word case1
	.word case2
	.word case3
	.word case4
	.word default

	
	.global moveState
moveState:
	cmp #5, &state
	jc default
	mov #state, r12
	add r12, r12
	mov jt(r12), r0

case1:
	mov &s, r12
	call #state_machine
	jmp out

case2:
	mov &s, r12
	call #state_machine
	jmp out

case3:
	mov &s, r12
	call #state_machine
	jmp out

case4:
	mov &s, r12
	call #state_machine
	jmp out

default:
	jmp out

out:
	ret
