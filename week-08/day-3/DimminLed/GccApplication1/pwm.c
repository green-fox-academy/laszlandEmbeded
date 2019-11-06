/*
 * CFile1.c
 *
 * Created: 11/6/2019 4:54:17 PM
 *  Author: Vaszja
 */ 

#include "pwm.h"

void init_timer0(timer_mode_t mode)
{
	TCCR0B = 0b00000010;
	DDRD |= 1 << DDRD6;
	
	switch(mode)
	{
		case FAST_PWM : TCCR0A = 0b10000011;
		break;
		case PHASE_CORRECT : TCCR0A = 0b10000001;
		break;
	}
}


void set_duty(uint8_t duty)
{
	OCR0A = duty * 255.0 / 100.0;
}

void init_timer2()
{
	TCCR2B = 0b00000111;
	TIMSK2 |= 1 << 0;
}