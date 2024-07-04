	PRESERVE8
			THUMB
		AREA |.text|, CODE, READONLY
	EXPORT __main
	
__main 
	LDR r0, = 0xFFC0FFFF
	LSLS r0, r0, #(32-16-8) ;#(32-w-p) w->width, p->starting posn from right
	LSRS r0, r0, #(32-8) ;#(32-w)
	
	LDR r0, = 0xFFC0FFFF
	MOVS r1, #16 ;#(p)
	MOVS r2, #8 ;#(w)
	MOVS r3, #(32-16-8) ;#(32-w-p)
	RORS r0, r0, r1
	LSRS r0, r0, r2
	RORS r0, r0, r3
stop B stop
	END
