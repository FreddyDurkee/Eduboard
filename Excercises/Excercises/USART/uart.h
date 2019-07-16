/*
* uart.h
*
* Created: 16.07.2019 13:55:32
*  Author: Dominika Wójcik
*/


#ifndef UART_H_
#define UART_H_


#define F_CPU  16000000UL
#define MYUBRR FOSC/2/BAUD-1
#define UART_BAUD 115200
#define __UBRR ((F_CPU+UART_BAUD*8UL) / (16UL*UART_BAUD)-1)

#include <avr/io.h>

void USART_Init_Transmission(unsigned int);
void USART_transmit_char(char data);
void USART_transmit_string(char *str);
void USART_transmit_int(int num);
void USART_transmit_float(float num, int precission);

#endif /* UART_H_ */