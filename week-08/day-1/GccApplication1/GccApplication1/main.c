/*
 * GccApplication1.c
 *
 * Created: 11/4/2019 4:09:13 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>


int main(void)
{
    DDRB = 1 << 5;
	uint8_t ON = 0;
	/* Replace with your application code */
    while (1) 
    {
		if (!(PINB & (1 << PINB7))) {
			_delay_ms(300);
			if (ON) {
				PORTB = 0 << 5;
				ON = 0;
				} else {
				PORTB = 1 << 5;
				ON = 1;
				}
    }
}
	}

