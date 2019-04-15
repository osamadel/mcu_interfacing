/*
 * main.c
 * toggle between slow and fast LED blink using ON-OFF switch
 *
 *  Created on: Apr 14, 2019
 *      Author: osama
 */
// necessary to define F_CPU if to use util/delay.h
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRA = 0b00000001;		// set PORTA.A0 to be OUTPUT, A1 to INPUT
	PORTA = 0b00000010;		// set PORTA.A0 to LOW, A1 to HIGH
	while (1) {
		if (PINA == 0x02) {	// test if A1 has 1 at its input
			PORTA = 0x03;
			_delay_ms(2000);
			PORTA = 0x02;
			_delay_ms(2000);
		} else {
			PORTA = 0x03;
			_delay_ms(300);
			PORTA = 0x02;
			_delay_ms(300);
		}
	}
	return 0;
}
