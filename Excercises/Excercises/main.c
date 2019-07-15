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

#define FOSC 1843200 // Clock Speed
#define BAUD 115200
#define MYUBRR FOSC/2/BAUD-1


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void leds_wave_blinking();
void switch_on_leds();
void USART_Transmit(unsigned char);
void USART_Init_Transmission(unsigned int);


int main(void)
{
	PCICR |= (1<<PCIE2);
	PCMSK2 |= (1<<PCINT19);
		
	DDRB |= LED1|LED2|LED3|LED4;
	DDRD |=  BUTTON1;
	
	PORTB |= 0b00111100;
	PORTD |= BUTTON1;
	
	USART_Init_Transmission(MYUBRR);
	
	sei();
    while (1) 
    {
		USART_Transmit('t');
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

void USART_Transmit(unsigned char data)
{
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
	//UCSR0B |= 0b01000000;
}

void USART_Init_Transmission(unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;

	UCSR0B = (1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
	}

ISR(PCINT2_vect){
	switch_on_leds();
}
	

