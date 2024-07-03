		PRESERVE8
			THUMB
		AREA |.text|, CODE, READONLY
	EXPORT __main
	
__main 
	LDR r0, = 1
	CMP r0, #3
	BHI default_case
	
	MOVS r2, #4
	MULS r0, r2, r0
	LDR r1, = BranchTable
	LDR r2, [r1,r0]
	BX r2
	ALIGN 4
	
BranchTable
	
	DCD	Dest0
	DCD Dest1
	DCD Dest2
	DCD Dest3
	
	
default_case
stop B stop

Dest0 LDR r0, = 0x10

stop1 B stop1

Dest1 LDR r0, = 0x20

stop2 B stop2

Dest2 LDR r0, = 0x30

stop3 B stop3

Dest3 LDR r0, = 0x40

	END
