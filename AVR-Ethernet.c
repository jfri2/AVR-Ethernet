/*
 * AVR_Ethernet.c
 *
 * Created: 5/31/2015 4:39:51 PM
 *  Author: John
 */ 

/**External oscillator frequency definition**/
#define F_CPU 16000000L

/**Pin assignments for spi.h**/
#define SCK		5
#define MOSI	3
#define MISO	4
#define SPIDDR	DDRB

#define CS0		2
#define CS0DDR	DDRB
#define CS0PORT	PORTB

#define CS1		5
#define CS1DDR	DDRD
#define CS1PORT	PORTD

/**Include files**/
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "spi.h"
#include "serial.c"

int main(void)
{
	InitUART();
	printf("\n\n**************************************************");
	printf("\nAVR-Ethernet");					//DEBUG
	printf("\n**************************************************\n");
	printf("\nInitalizing SPI...");				//DEBUG
	SpiMasterInit();
	printf("initialization done.");				//DEBUG
	

	
    while(1)
    {
		int user_input = 0xFFFF;
			
	    printf("\n\nSelect an option:");
	    printf("\n\t0: Option zero");
	    printf("\n\t1: Option one\n");
		 
		scanf("%d", &user_input);
		
		switch (user_input)
		{
			case 0 :
			printf("\nYou entered 0");
			break;
			case 1 :
			printf("\nYou entered 1");
			break;
			default	:
			printf("\nERROR, invalid entry");
			break;
		}
		
		while(1)
		{
		}
    }
}