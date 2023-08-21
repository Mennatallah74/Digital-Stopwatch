/*
 * Timer.c

 *
 *  Created on: Aug 20, 2023
 *      Author: Menna
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "avr/io.h"
#include "TIMER.h"

void Timer_Init()
{

	/*enabling  interrupt overflow for the timer*/
	SET_BIT(TIMSK,TIMSK_TOIE);
	/* choosing clock source to be clk/8 */
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

}
