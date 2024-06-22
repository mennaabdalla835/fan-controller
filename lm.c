/*
 * lm35.c
 *
 *      Author: merna akram
 */
#include "lm.h"
#include "adc.h"

/*******************************************************************************
 *                       FUNCTION DEFINITION
 ******************************************************************************/
/*
 * description: function to calculate the temperature from the ADC value
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value=0;
	uint16 adc_value=0;
	/* read the ADC value */
	adc_value=ADC_readChannel(SENSOR_CHANNEL_ID);
	/* calculate the temperature from the ADC value */
	temp_value=(uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLTAGE)/(SENSOR_MAX_VOLTAGE * ADC_MAX_VALUE));
	return temp_value;
}
