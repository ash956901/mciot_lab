		PRESERVE8
			THUMB
		AREA |.text|, CODE, READONLY
	EXPORT __main
	
__main 
		LDR r0, = 0x20000000
		LDR r1, = 0x20000120
		MOVS r2, #128
copy_loop
		LDMIA r0!,{r4-r7}
		STMIA r1!,{r4-r7}
		LDMIA r0!,{r4-r7}
		STMIA r1!,{r4-r7}
		LDMIA r0!,{r4-r7}
		STMIA r1!,{r4-r7}
		LDMIA r0!,{r4-r7}
		STMIA r1!,{r4-r7}
		SUBS r2, r2, #64
		BNE copy_loop
stop B stop
END
