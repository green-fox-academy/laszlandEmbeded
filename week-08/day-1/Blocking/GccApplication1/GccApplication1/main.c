/*
 * GccApplication1.c
 *
 * Created: 11/4/2019 4:37:20 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>



void custom_delay_ms(int ms)
{
	for (int i = 0; i < ms; i++) {
		_delay_ms(1);
	}
}

void blink_at_mhz(int mhertz)
{
	int delay_time = 500000 / mhertz;
	PORTB = 1 << 5;
	custom_delay_ms(delay_time);
	PORTB = 0 << 5;
	custom_delay_ms(delay_time);
}


int main(void)
{
    /* Replace with your application code */
	
	DDRB = 1 << 5;
	int frequency[6] = {500, 1000, 2000, 4000, 2000, 1000};
	
    while (1) 
    {
		for (int i = 0; i < 6; i++) {
			blink_at_mhz(frequency[i]);
		}
	}
}

