/*C12-C15*/
#include <stdio.h>
#include "NUC1xx.h"
#include "Driver/DrvSYS.h"
#include "Driver/DrvGPIO.h"
#include "Driver/DrvUART.h"

/*Macros*/

//Initialise for output
#define INIT_LED0 DrvGPIO_Open(E_GPC,12,E_IO_OUTPUT)
#define INIT_LED1 DrvGPIO_Open(E_GPC,13,E_IO_OUTPUT)
#define INIT_LED2 DrvGPIO_Open(E_GPC,14,E_IO_OUTPUT)
#define INIT_LED3 DrvGPIO_Open(E_GPC,15,E_IO_OUTPUT)

//On and off states
#define LED0_ON DrvGPIO_ClrBit(E_GPC,12)
#define LED0_OFF DrvGPIO_SetBit(E_GPC,12)
#define LED1_ON DrvGPIO_ClrBit(E_GPC,13)
#define LED1_OFF DrvGPIO_SetBit(E_GPC,13)
#define LED2_ON DrvGPIO_ClrBit(E_GPC,14)
#define LED2_OFF DrvGPIO_SetBit(E_GPC,14)
#define LED3_ON DrvGPIO_ClrBit(E_GPC,15)
#define LED3_OFF DrvGPIO_SetBit(E_GPC,15)

//delay
#define DELAY DrvSYS_Delay(300000)
void init_led(void){
	
	INIT_LED0;
	INIT_LED1;
	INIT_LED2;
	INIT_LED3;
	
	LED0_OFF;
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	
	
	}

int32_t main(void){
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	
	init_led();
	
	while(1){
		LED0_ON;
		DELAY;
		LED0_OFF;
		DELAY;
		LED1_ON;
		DELAY;
		LED1_OFF;
		DELAY;
		LED2_ON;
		DELAY;
		LED2_OFF;
		DELAY;
		LED3_ON;
		DELAY;
		LED3_OFF;
		DELAY;
		
		
		}
	
}

