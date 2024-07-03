#include <stdio.h>
#include "NUC1xx.h"
#include "Driver/DrvGPIO.h"
#include "Driver/DrvSYS.h"
#include "NUC1xx-LB_002/ScanKey.h"
#include "NUC1xx-LB_002/LCD_Driver.h"

int32_t main(void){
	int8_t number;
	char TEXT0[16]="Smpl_TXT_KEY_PR";
	char TEXT1[16]="KEYPAD:        ";

	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	
	Initial_panel();
	clr_all_panel();

	print_lcd(0,TEXT0);
	OpenKeyPad();
	
	while(1){
		  number = Scankey(); 	      // scan keypad to input
		sprintf(TEXT1+8,"%d",number); // print scankey input to string			  
		print_lcd(1, TEXT1);          // display string on LCD
		DrvSYS_Delay(5); 	
	}
}

	
