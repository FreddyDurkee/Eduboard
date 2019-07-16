/*
* adc.c
*
* Created: 16.07.2019 14:26:19
*  Author: Dominika Wójcik
*/

#include "adc.h"
#include "stdlib.h"

void adc_init(){
	ADMUX |= (3<<REFS0);
	ADMUX |= (1<<ADLAR);
	ADMUX |= ADC1;

	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADATE);
	ADCSRA |= (7<<ADPS0);
	ADCSRA |= (1<<ADSC);
}

float get_8bit_voltage_value(){
	int adc = ADCH;
	float vin = (adc * 1.1)/256.0;
	//return (adc * 1.1)/256.0;
	return vin;
}
