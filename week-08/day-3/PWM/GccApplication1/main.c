/*
 * GccApplication1.c
 *
 * Created: 11/6/2019 2:21:53 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

typedef enum {
	FAST_PWM,
	PHASE_CORRECT
	}timer_type_t;

void init(timer_type_t type)
{
	TCCR0B = 0b00000010;
	DDRD |= 1 << DDRD6;
	switch (type)
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


int main(void)
{
    /* Replace with your application code */
	uint8_t duty = 0;
	init(PHASE_CORRECT);
	
    while (1) 
    {
		set_duty(duty);
		_delay_ms(20);
		duty++;
		
		if(duty > 100){
			duty = 0;
    }
}
}

