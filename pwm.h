/*
 *file name: pwm.h
 *description: header file for PWM
 * Author: merna akram
 */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
/******************************************************************************
 *                           FUNCTION PROTO TYPE
 *****************************************************************************/
/*
 * description: function that start the timer0 with PWM mode
 */
void PWM_timer0(uint8 duty_cycle);

#endif /* PWM_H_ */
