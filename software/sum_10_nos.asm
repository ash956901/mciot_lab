	PRESERVE8	
			THUMB
		AREA |.text|, CODE, READONLY
	EXPORT __main
	
DATAIN EQU 0x20000000
SUM EQU 0x20000040

__main
		LDR r0, = DATAIN
		MOVS r1, #10
		MOVS r2, #0
add_loop
		LDM r0!, {r3}
		ADDS r2, r2, r3
		SUBS r1, r1 ,#1
		BNE add_loop
		LDR r0, = SUM
		STR r2, [r0]
stop B stop
		END
		
