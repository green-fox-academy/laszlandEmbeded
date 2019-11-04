/*
 * GccApplication1.c
 *
 * Created: 11/4/2019 4:37:20 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	
	DDRB = 1 << 5;
	uint8_t counter = 0;
	PORTB = 0 << 5;
	
    while (1) 
    {
	
		if (!(PINB & (1 << PINB7))) {
			_delay_ms(300);
			counter++;
		}
		
		if (counter == 5) {
			PORTB = 1 << 5;
		}
	}
}

