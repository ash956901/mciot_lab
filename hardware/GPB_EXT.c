#include <stdio.h>
#include "NUC1xx.h"
#include "Driver/DrvSYS.h"
#include "Driver/DrvGPIO.h"
#include "Driver/DrvUART.h"

void EINT1CALLBACK(void){
	DrvGPIO_ClrBit(E_GPB,11);
	DrvSYS_Delay(1000000000);
	DrvGPIO_SetBit(E_GPB,11);
	DrvSYS_Delay(1000000000);
}

int main(void){
	UNLOCKREG();
	DrvSYS_SetOscCtrl(E_SYS_XTL12M,1);
	DrvSYS_Delay(500);
	DrvSYS_SelectHCLKSource(0);
	LOCKREG();
	
	
	DrvGPIO_Open(E_GPB,11,E_IO_OUTPUT);
	DrvGPIO_Open(E_GPB,15,E_IO_OUTPUT);
	DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE,E_MODE_EDGE,EINT1CALLBACK);
	Initial_panel();
	clr_all_panel();
	while(1){}
}
	
	
	
