/*
 * adc.h
 *
 * Created: 16.07.2019 14:26:32
 *  Author: Dominika Wójcik
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

# define PRESCALER_2 (1<<ADPS0)
# define PRESCALER_4 (2<<ADPS0)
# define PRESCALER_8 (3<<ADPS0)
# define PRESCALER_16 (4<<ADPS0)
# define PRESCALER_32 (5<<ADPS0)
# define PRESCALER_64 (6<<ADPS0)
# define PRESCALER_128 (7<<ADPS0)

#define REF_11 (3<<REFS0);
#define REF_AVCC (1<<REFS0);

void adc_init();
float get_8bit_voltage_value(uint8_t channel);
float get_10bit_voltage_value(uint8_t channel);
uint16_t make_measurement(uint8_t channel);

#endif /* ADC_H_ */