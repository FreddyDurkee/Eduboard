/*
* adc.c
*
* Created: 16.07.2019 14:26:19
*  Author: Dominika Wójcik
*/

#include "adc.h"
#include "stdlib.h"

void adc_init(){
	ADMUX |= REF_11;
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADATE);
	ADCSRA |= PRESCALER_128;
}

float get_8bit_voltage_value(uint8_t channel){
	ADMUX |= (1<<ADLAR);
	make_measurement(channel);
	int adc = ADCH;
	float vin = (adc * 1.1)/256.0;
	return vin;
}

float get_10bit_voltage_value(uint8_t channel){
	uint16_t adc = make_measurement(channel);
	float vin = (adc * 1.1)/1024;
	return vin;
}

uint16_t make_measurement(uint8_t channel){
	ADMUX = (ADMUX & 0b11110000) | channel;
	ADCSRA |= (1<<ADSC);
	return ADCW;
}
