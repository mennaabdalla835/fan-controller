/*
 * file name:motor.c
 * description: source file for DC MOTOR driver
 * Author: merna akram
 */

#include "motor.h"
#include "gpio.h"
#include "common_macros.h"
#include "pwm.h"
#include <avr/io.h>

/*
 * description:
 * function to setup the direction for motor's two pins
 * and to stop the motor at first
 */
void DcMotor_Init(void)
{
	/* set pin0 and pin1 of the motor as output pins */
	 GPIO_setupPinDirection(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1_ID,PIN_OUTPUT);
	 GPIO_setupPinDirection(DC_MOTOR_PORT_ID,DC_MOTOR_PIN2_ID,PIN_OUTPUT);

	 /* stop motor at first by put pin0 and pin1 as logic low pins */
	 GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
	 GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	uint8 duty_cycle;
	duty_cycle=(uint8)((speed/100.0f)*255);
	PWM_timer0(duty_cycle);
	/* set the output pins with the state of motor */
	PORTB=(PORTB & 0xFC) | (state & 0x03);

}
