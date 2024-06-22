/*
 * file name: adc.c
 * description: source file for ADC driver
 * Author: merna akram
 */

#include "adc.h"
#include "common_macros.h"
#include <avr/io.h>
/*******************************************************************************
 *                      FUNCTIONS DEFINITION
 ******************************************************************************/
/*
 *  description: function to initialize the ADC driver
 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX=(ADMUX & 0x3F) | ((Config_Ptr->voltage)<<6);
	ADCSRA|=(1<<ADEN);
	ADCSRA=(ADCSRA & 0xF8) |(Config_Ptr ->prescaler);

}
uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX=(ADMUX & 0xE0) |(channel_num & 0x07);
	SET_BIT(ADCSRA,ADSC); /* Start conversion */
	while (BIT_IS_CLEAR(ADCSRA,ADIF)){}; /* wait for the conversion to compelete */
	SET_BIT(ADCSRA,ADIF); /* clear ADIF by write 1 */
	return ADC; /* read the digital value from the data register */

}
