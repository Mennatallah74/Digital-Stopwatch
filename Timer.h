/*
 * Timer.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Menna
 */

#ifndef TIMER_H_
#define TIMER_H_

#define TCCR0_FOC0 7
#define TCCR0_WGM00 6
#define TCCR0_WGM01 3
#define TCCR0_COM00 4
#define TCCR0_COM01 5
#define TCCR0_CS00  0
#define TCCR0_CS01  1
#define TCCR0_CS02  2
#define TIMSK_TOIE  0
#define TIMSK_OCIE  1

void Timer_Init();


#endif /* TIMER_H_ */
