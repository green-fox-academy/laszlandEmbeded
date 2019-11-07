/*
 * GccApplication1.c
 *
 * Created: 11/7/2019 1:41:32 PM
 * Author : Vaszja
 */ 

#include <avr/io.h>
#include <stdio.h>

void init()
{
	ADCSRA |= 0b11100000;
	ADCSRB |= 0;
	
	DDRD |= 1 << DDRD6;
}


int main(void)
{
    /* Replace with your application code */
	
	init();
	
	uint8_t result1;
	uint8_t result2;
	
	uint16_t combination_result;
	
    while (1) 
    {
		result1 = ADCL;
		result2 = ADCH;
		combination_result = (((uint16_t)result2 << 8) | result1);
    }
}

