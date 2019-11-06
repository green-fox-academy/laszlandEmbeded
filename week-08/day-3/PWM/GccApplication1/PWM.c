#include "PWM.h"

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