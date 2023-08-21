/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Menna
 */
#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "TIMER.h"

	u8 seconds = 0;
	u8 minutes = 0;
	u32 overflow = 0;
	/* 7 segment display values from 0 to 9*/
	u8 segDisplay[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int main(void)
{
/*initialization of 7 segments ports*/
	DIO_SetPortDirection(DIO_PORTA,DIO_ALL_OUTPUT);
	DIO_SetPortDirection(DIO_PORTB,DIO_ALL_OUTPUT);
	DIO_SetPortDirection(DIO_PORTC,DIO_ALL_OUTPUT);
	DIO_SetPortDirection(DIO_PORTD,DIO_ALL_OUTPUT);
	DIO_SetPortValue(DIO_PORTD,0X3F);
	DIO_SetPortValue(DIO_PORTC,0X3F);
	DIO_SetPortValue(DIO_PORTA,0X3F);
	DIO_SetPortValue(DIO_PORTB,0X3F);

	sei();
	Timer_Init();
	TCNT0 = 192;
		while(1){

		}

}
/*overflow interrupt*/
ISR(TIMER0_OVF_vect)
{
	overflow++;
	if(overflow == 3906)
	{

		overflow = 0;
		TCNT0 = 192;
		seconds++;


		if(seconds == 60)
		{
			minutes++;

			seconds = 0;
		}
		if(minutes == 60)
			minutes = 0;
	}
	DIO_SetPortValue(DIO_PORTD,segDisplay[seconds%10]);
	DIO_SetPortValue(DIO_PORTC,segDisplay[seconds/10]);
	DIO_SetPortValue(DIO_PORTA,segDisplay[minutes%10]);
	DIO_SetPortValue(DIO_PORTB,segDisplay[minutes/10]);



}

