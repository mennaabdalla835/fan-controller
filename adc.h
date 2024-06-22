/*
 *      file name: adc.h
 *      description:header file for ADC driver

 *      Author: merna akram
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
/*******************************************************************************
 *                            DEFINITIONS
 ******************************************************************************/
#define ADC_MAX_VALUE 1023
#define ADC_REF_VOLTAGE 2.56

typedef enum {
	AREF,AVCC,RESERVED,INTERNAL
}ADC_volatage;

typedef enum {
	F_CPU_CLOCK_2=1,F_CPU_CLOCK_4,F_CPU_CLOCK_8,F_CPU_CLOCK_16,F_CPU_CLOCK_32,
	F_CPU_CLOCK_64,F_CPU_CLOCK_128
}ADC_prescaler;
typedef struct {
	ADC_volatage voltage;
	ADC_prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                         FUNCTIONS PROTOTYPES
 ******************************************************************************/
/*
 *  description: function to initialize the ADC driver
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * description:
 * function to read the analog value from ADC channel and convert it to digital value
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
