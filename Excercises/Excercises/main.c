/*
 * Excercises.c
 *
 * Created: 08.07.2019 18:54:00
 * Author : Dominika Wójcik
 */ 

#define F_CPU   16000000UL

#define LED1 (1<<PB5)
#define LED2 (1<<PB4)
#define LED3 (1<<PB3)
#define LED4 (1<<PB2)

#define LED1_ON PORTB &= ~LED1;
#define LED1_OFF PORTB |= LED1;

#define LED2_ON PORTB &= ~LED2;
#define LED2_OFF PORTB |= LED2;

#define LED3_ON PORTB &= ~LED3;
#define LED3_OFF PORTB |= LED3;

#define LED4_ON PORTB &= ~LED4;
#define LED4_OFF PORTB |= LED4;

#define BUTTON1 (1<<PD3)


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void leds_wave_blinking();
void switch_on_leds();

int main(void)
{
	PCICR |= (1<<PCIE2);
	PCMSK2 |= (1<<PCINT19);
		
	DDRB |= LED1|LED2|LED3|LED4;
	DDRD |=  BUTTON1;
	
	PORTB |= 0b00111100;
	PORTD |= BUTTON1;
	
	sei();
    while (1) 
    {
		leds_wave_blinking();
    }
}



void leds_wave_blinking(){
	uint8_t i, led=4;
	for(i=0; i<4; i++){
		PORTB &= ~led;
		_delay_ms(500);
		PORTB |= led;
		led = led*2;
	}
}
void switch_on_leds(){
	PORTB &= ~(LED1|LED2|LED3|LED4);
}

ISR(PCINT2_vect){
	switch_on_leds();
}
	

