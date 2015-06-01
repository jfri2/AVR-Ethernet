/**

spi.h

	device:
	0: W5200
	1: SD Card
	
John Fritz
5/31/2015

This file includes initialization and transceiver functions for the hardware SPI on the
ATmega328p microcontroller. 

#define statements must be properly defined for interface with hardware to function correctly. 

**/


/**Function prototypes**/
void SpiMasterInit(void);
uint8_t SpiMasterTranscieve(uint8_t, uint8_t);

void SpiMasterInit(void)
{
	/**
	SpiMasterInit
	- sets data direction on spi port to output
	- sets data direction on cs pins to output
	- writes CS high (active low) when not in use
	- enables spi, master, MSB transmit first, SCK low when idle, sample on leading edge, SCK = FOSC/64
	**/
	
	SPIDDR	|= (1<<MOSI) | (1<<SCK);
	CS0DDR	|= (1<<CS0);			
	CS0PORT	|= (1<<CS0);
	CS1DDR	|= (1<<CS1);
	CS1PORT |= (1<<CS1);
	SPCR	|= (1<<SPE) | (1<<MSTR) | (1<<SPR1);	
}

uint8_t SpiMasterTranscieve(uint8_t device, uint8_t send_data)
{
	/**
	SpiMasterTranscieveCS0
	- transmits and receives data (one byte at time) from spi devices
	- returns one data byte per function call
	- toggles proper CS pin on and off for slave selection	
	**/
	
	uint8_t return_data = 0;	
	
	if (device == 0)
	{
		CS0PORT &= ~(1<<CS0);				//sets CS0 low to select salve0 
		SPDR = send_data;					//put data to send into SPI data register, start transmission
		while(!(SPSR & (1<<SPIF)));			//wait until transmission is complete
		return_data = SPDR;					//store data from SPI data register
		CS0PORT |= (1<<CS0);				//sets CS0 high to de-select slave0
	}
	else if (device == 1)
	{
			CS1PORT &= ~(1<<CS1);				//sets CS0 low to select salve0
			SPDR = send_data;					//put data to send into SPI data register, start transmission
			while(!(SPSR & (1<<SPIF)));			//wait until transmission is complete
			return_data = SPDR;					//store data from SPI data register
			CS1PORT |= (1<<CS1);				//sets CS0 high to de-select slave0
	}
	
	return(return_data);	 
}