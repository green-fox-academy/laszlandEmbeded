/*
 * GccApplication1.c
 *
 * Created: 11/7/2019 1:41:32 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

typedef enum pwm_type {
	FAST_PWM,
	PHASE_CORRECT
} pwm_t;
	
void timer0_init(pwm_t type)
{
	switch (type) {
		case FAST_PWM :
		TCCR0A = 0b10000011;
		TCCR0B = 0b00000010;
		break;
		case PHASE_CORRECT :
		TCCR0A = 0b10000011;
		TCCR0B = 0b00000010;
		break;
	}
	DDRD |= 1 << DDRD6;
}

void init()
{
	ADMUX |= 1 << 5;		// left adjusted result
	ADCSRA |= 0b11100000;
	ADCSRB |= 0;
}

void set_duty(uint8_t duty_byte)
{
	OCR0A = duty_byte;
}


int main(void)
{
    /* Replace with your application code */
	
	timer0_init(PHASE_CORRECT);
	init();
	
	uint8_t result1;
	uint8_t result2;
	
	uint16_t combination_result;
	
    while (1) 
    {
		result1 = ADCL;
		result2 = ADCH;
		//combination_result = (((uint16_t)result2 << 8) | result1);
		
		set_duty(result2);
		_delay_ms(100);
		
		
    }
}

