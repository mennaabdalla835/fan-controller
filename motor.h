/*
 *file name: motor.h
 *description:header file for DC MOTOR driver
 * Author: merna akram
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"
/*******************************************************************************
 *                            DEFINITIONS
 ******************************************************************************/
#define DC_MOTOR_PORT_ID      PORTB_ID
#define DC_MOTOR_PIN1_ID      PIN0_ID
#define DC_MOTOR_PIN2_ID      PIN1_ID

typedef enum
{
	MOTOR_STOP,MOTOR_CLOCK_WISE,MOTOR_ANTI_CLOCK_WISE
}DcMotor_State;
/*******************************************************************************
 *                           FUNCTIONS PROTOTYPE
 ******************************************************************************/
/*
 * description:
 * function to setup the direction for motor's two pins
 * and to stop the motor at first
 */
void DcMotor_Init(void);
/*
 * description:
 * function that responsible for the rotate direction of the motor or stop the motor
 * and send the required duty cycle to the PWM
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
