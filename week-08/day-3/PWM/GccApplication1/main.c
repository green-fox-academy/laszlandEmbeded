/*
 * GccApplication1.c
 *
 * Created: 11/6/2019 2:21:53 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "PWM.h"

int main(void)
{
    /* Replace with your application code */
	uint8_t duty = 0;
	init(PHASE_CORRECT);
	
    while (1) 
    {
		set_duty(duty);
		_delay_ms(10);
		duty++;
		
		if(duty > 100){
			duty = 0;
    }
}
}

