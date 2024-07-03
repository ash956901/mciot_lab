		PRESERVE8
			THUMB
		AREA |.text|, CODE, READONLY
	EXPORT __main
	
__main 
		LDR r0,=0x00000010
		ASRS r1,r0,#2
		LSLS r2,r0,#1
stop B stop
END
