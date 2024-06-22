/*
 * file name:project3.c
 * description:fan controller project
 *   Author: merna akram
 */
#include "adc.h"
#include "lcd.h"
#include "lm.h"
#include "motor.h"
#include "pwm.h"

int main ()
{
	uint8 temp;
	ADC_ConfigType config={INTERNAL,F_CPU_CLOCK_8};
	ADC_init(&config);
	LCD_init();
	DcMotor_Init();
	LCD_displayString("fan is ");
	LCD_moveCursor(1,0);
	LCD_displayString("temp= ");
	while (1)
	{
		temp=LM35_getTemperature();
		if (temp < 30)
		{
			DcMotor_Rotate(MOTOR_STOP,0);
			LCD_moveCursor(0,8);
			LCD_displayString("off");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}
		else if ((temp < 60)&&(temp >= 30))
		{
			DcMotor_Rotate(MOTOR_CLOCK_WISE,25);
		    LCD_moveCursor(0,8);
		    LCD_displayString("on ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}
		else if ((temp < 90) &&(temp >= 60))
		{
			DcMotor_Rotate(MOTOR_CLOCK_WISE,50);
		    LCD_moveCursor(0,8);
		    LCD_displayString("on ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}
		else if ((temp < 120)&&(temp >= 90))
		{
			DcMotor_Rotate(MOTOR_CLOCK_WISE,75);
		    LCD_moveCursor(0,8);
		    LCD_displayString("on ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}
		else if (temp >= 120)
		{

			DcMotor_Rotate(MOTOR_CLOCK_WISE,100);
		    LCD_moveCursor(0,8);
		    LCD_displayString("on");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);

		}

	}
}

