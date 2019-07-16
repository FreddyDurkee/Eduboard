/*
 * adc.h
 *
 * Created: 16.07.2019 14:26:32
 *  Author: Dominika Wójcik
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

# define ADC1 (1<<MUX0)



void adc_init();
float get_8bit_voltage_value();

#endif /* ADC_H_ */