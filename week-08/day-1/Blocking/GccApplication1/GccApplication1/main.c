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
	uint8_t flag = 0;
	
    while (1) 
    {
		
		if (flag) {
			PORTB = 1 << 5;
			_delay_ms(300);
			PORTB = 0 << 5;
			_delay_ms(300);
		} else {
			if (!(PINB & (1 << PINB7))) {
				flag = 1;
			}
		}
    }
}

