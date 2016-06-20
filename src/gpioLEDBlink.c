/*
 * =====================================================================================
 *
 *       Filename:  gpioLEDBlink.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  15/05/2016 12:15:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Francisco Helder (), helderhdw@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include "gpioLED.h"

/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/
#define MSEG                        (0x3FFFFFF)


/*****************************************************************************
**                INTERNAL FUNCTION PROTOTYPES
*****************************************************************************/
//static void Delay(unsigned int count);


/*FUNCTION*-------------------------------------------------------
*
* Function Name : main
* Comments      :
*END*-----------------------------------------------------------*/
int main() {
    int pinIn = 15;
    int pinOut = 12;

    ledInit(pinIn, DIR_INPUT);
    ledInit(pinOut, DIR_OUTPUT);

    while(TRUE){

  		if(butonHigh(pinIn)){ //Entrada do PIN para INPUT
        ledHigh(pinOut);
  		}else{
        ledLow(pinOut);
  		}
    }

    return(0);
}

int butonHigh(int nPin){
	int *up = (int *) (GPIO_INSTANCE_ADDRESS + GPIO_DATAIN);
	int press = *up;

	if(press & (1<<nPin)){
      return PIN_HIGH;
  }	else {
      return PIN_LOW;
    }
}
