#include <avr/io.h>


typedef enum {
	FAST_PWM,
	PHASE_CORRECT
}timer_type_t;

void init(timer_type_t type);
void set_duty(uint8_t duty);