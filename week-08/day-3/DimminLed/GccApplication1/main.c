/*
 * GccApplication1.c
 *
 * Created: 11/6/2019 4:44:28 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

#include "pwm.h"



uint8_t counter = 0;
const uint8_t cntr_max = 80;
uint8_t brighten = 1;

ISR(TIMER2_OVF_vect)
{
	counter++;
	
	if(counter >= cntr_max) {
		brighten = !brighten;
		counter = 0;
	}
}

void init()
{
	timer_mode_t mode = PHASE_CORRECT;
	init_timer0(mode);
	
	sei();
	init_timer2();
}




int main(void)
{
	init();
	uint8_t duty = 0;
	
	while(1)
	{
		set_duty(duty);
		_delay_ms(100);
		
		if (brighten)
		{
			duty += 5;
			
			if (duty > 100)
			{
				duty = 100;
			}
		}
		else
		{
			duty -= 5;
			
			if (duty < 0)
			{
				duty = 0;
			}
		}
	}
}

