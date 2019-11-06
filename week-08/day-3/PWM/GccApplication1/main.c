/*
 * GccApplication1.c
 *
 * Created: 11/6/2019 2:21:53 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

void init()
{
	
	TCCR0A = 0b10000011;    // set fast PWM mode (last 2 bits), 
	TCCR0B = 0b00000010;    // set fast PWM mode (3. bit), set prescaler 8
	//OCR0A = 0x7f;
	DDRD |= 1 << DDRD6;     // PD6 pin set as output
}

void set_duty(uint8_t duty)
{
	OCR0A = duty * 255.0 / 100.0;
}


int main(void)
{
    /* Replace with your application code */
	uint8_t duty = 0;
	init();
	
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

