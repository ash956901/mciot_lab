#include <stdio.h>
#include "NUC1xx.h"
#include "Driver/DrvSYS.h"
#include "Driver/DrvGPIO.h"
#include "NUC1xx-LB_002/Seven_Segment.h"

void seg_display(int16_t value){
	int8_t digit;
	digit=value/10;
	close_seven_segment();
	show_seven_segment(1,digit);
	DrvSYS_Delay(5000);
	
	value=value-digit*10;
	digit=value;
	close_seven_segment();
	show_seven_segment(0,digit);
	DrvSYS_Delay(5000);
	
}

int32_t main(void){
	
	int val=0;
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	
	while(1){
			DrvSYS_Delay(500);
			val++;
		  if(val>=100){
				val=0;
				}
			seg_display(val);
	}
	
	
}
