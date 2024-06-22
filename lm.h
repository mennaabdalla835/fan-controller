/*
 * file name:lm35.h
 * description: header file for temperature sensor driver
 *  Author: merna akram
 */

#ifndef LM35_H_
#define LM35_H_
#include "std_types.h"
/*******************************************************************************
 *                            DEFINITIONS
 ******************************************************************************/
#define SENSOR_CHANNEL_ID       2
#define SENSOR_MAX_VOLTAGE     1.5
#define SENSOR_MAX_TEMPERATURE 150

/*******************************************************************************
 *                        FUNCTIONS PROTOTYPE
 ******************************************************************************/
/*
 * description: function to calculate the temperature from the ADC value
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_H_ */
