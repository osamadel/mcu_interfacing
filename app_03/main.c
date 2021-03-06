/*
 * main.c
 *
 * 7 segments with DIP switch
 *
 *  Created on: Apr 14, 2019
 *      Author: osama
 */
#include <avr/io.h>
#include <util/delay.h>

enum segment {A=0,B,C,D,E,F,G};
unsigned int numbers[11][8] = {
		{A,B,C,D,E,F,-1},		// 0
		{B,C,-1},				// 1
		{A,B,E,D,G,-1},			// 2
		{A,B,C,D,G,-1},			// 3
		{B,C,F,G,-1},			// 4
		{A,C,D,F,G,-1},			// 5
		{A,C,D,E,F,G,-1},		// 6
		{A,B,C,-1},				// 7
		{A,B,C,D,E,F,G,-1}, 	// 8
		{A,B,C,D,F,G,-1},		// 9
		{E,F}
};

void print7Seg(int i) {
	PORTA = 0xff;
	for (int j=0; numbers[i][j] != -1; j++)
		PORTA &= ~(0b00000001 << numbers[i][j]);	// Set PORTA bits at numbers to 0
}

void blink(void) {
	PORTA = 0b10111111;
	_delay_ms(200);
	PORTA = 0b01111111;
	_delay_ms(200);
}

int main(void) {
	// set portA to be output
	DDRA = 0b11111111;
	// set portC to be input
	DDRD = 0b00000000;
	// enable pull-up resistors in portC
	PORTD = 0b11111111;
	// top-scope counter i
	unsigned int i;
	char found;
	char SW;

	while (1){
		found = 0;
		SW = PIND;
		for (i=0; i<=7; i++) {
//				PORTA = PIND;
//				_delay_ms(1000);
			if (SW%2 == 0) {
				found = 1;
				print7Seg(i);
				_delay_ms(1000);
				print7Seg(7);
				_delay_ms(300);
				SW>>1;
				break;
			}
		} // end for

		if (!found) {
			print7Seg(10);
			_delay_ms(2000);
		} // end if

		blink();
	} // end while(1)


	return 0;
} // end main


