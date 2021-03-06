/*
 * main.c
 * LED train
 *
 *  Created on: Apr 14, 2019
 *      Author: osama
 */
#define NUMBER_LED 8
#include <avr/io.h>
#include <util/delay.h>

int main (void) {
	// initialization
	DDRA = 0xff;
	PORTA = 0x00;
	while (1) {
		PORTA = 0x01;
		for (int i=0; i<=NUMBER_LED-1; i++) {
			_delay_ms(500);
			PORTA <<= 1;
		}
		PORTA = 0x80;
		for (int i=0; i<=NUMBER_LED-1; i++) {
			_delay_ms(500);
			PORTA >>= 1;
		}
	}
}
