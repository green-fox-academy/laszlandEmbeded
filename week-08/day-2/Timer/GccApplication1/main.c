/*
 * GccApplication1.c
 *
 * Created: 11/5/2019 3:10:43 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t counter = 0;
const uint8_t cntr_max = 10;

ISR(TIMER0_OVF_vect)
{
	if (counter >= cntr_max) {
		PINB = 1 << PINB5;
		counter = 0;
	}
	counter++;
}


void init()
{
	// Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
	// With this you also set the clock source to CLK_io and you will also turn on the timer!
	TCCR0B |= 0b00000101;
	TIMSK0 |= 0x01;
	sei();

	// Set the PB5 LED pin to output
	DDRB |= 1 << 5;
}



int main(void)
{

	
	
	// Don't forget to call the init function!
	init();
	while (1)
	{
		// If TC0 counter overflow occurred (TOV0 flag is set) toggle the LED and write "1" to that flag
		// (this will clear it, it's confusing, but this is how it works)
		
	}
}



