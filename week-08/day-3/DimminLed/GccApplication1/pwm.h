/*
 * IncFile1.h
 *
 * Created: 11/6/2019 4:49:31 PM
 *  Author: Vaszja
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include <avr/io.h>

typedef enum {
	FAST_PWM,
	PHASE_CORRECT
	} timer_mode_t;
	
void init_timer0(timer_mode_t mode);
void init_timer2();
void set_duty(uint8_t duty);


#endif /* INCFILE1_H_ */