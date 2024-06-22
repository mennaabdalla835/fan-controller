/*
 *file name: pwm.c
 *description: source file for PWM
 * Created on: Oct 9, 2022
 * Author: merna akram
 */
#include "pwm.h"
#include "gpio.h"
#include <avr/io.h>

/*
 * description: function that start the timer0 with PWM mode
 */
void PWM_timer0(uint8 duty_cycle)
{

	TCNT0=0;
	OCR0=duty_cycle;
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	TCCR0=(1<<WGM01) | (1<<WGM00) | (1<<COM01) |(1<<CS01);
}
