/*
* uart.c
*
* Created: 16.07.2019 13:55:48
*  Author: Dominika Wójcik
*/

#include "uart.h"
#include "avr/io.h"
#include <stdlib.h>

void USART_transmit_float(float num, int precission)
{
	char c[10];
	int inum = num;
	int numSize = sizeof(inum) + precission;
	dtostrf(num, numSize, precission, c);
	USART_transmit_string(c);
}

void USART_transmit_int(int num)
{
	char c[6];
	itoa(num, c,10);
	USART_transmit_string(c);
}

void USART_transmit_string(char *str)
{
	while(*str){
		USART_transmit_char(*str++);
	}
}


void USART_transmit_char(char data)
{
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}



void USART_Init_Transmission(unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;

	UCSR0B = (1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
}
