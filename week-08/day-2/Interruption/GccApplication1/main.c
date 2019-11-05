/*
 * GccApplication1.c
 *
 * Created: 11/5/2019 2:10:29 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(PCINT0_vect)
{
	PORTB ^= 1 << 5;
	
}

void init()
{
	PCMSK0 |= 1 << PCINT7;
	PCICR |= 1 << PCIE0;
	sei();
	DDRB = 1 << 5;
}


int main(void)
{
	init();
    while (1) 
    {
    }
}

