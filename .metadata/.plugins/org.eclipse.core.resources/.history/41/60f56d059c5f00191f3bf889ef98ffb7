#include "libs/L_STD_TYPES.h"
#include "MDIO/MDIO_interface.h"
#include "H7Segments_interface.h"
#include <util/delay.h>

void initialize8LEDs(void) {
	MDIO_SetPinDirection(PORTB, 0, OUTPUT);
	MDIO_SetPinDirection(PORTB, 1, OUTPUT);
	MDIO_SetPinDirection(PORTB, 2, OUTPUT);
	MDIO_SetPinDirection(PORTB, 3, OUTPUT);
	MDIO_SetPinDirection(PORTB, 4, OUTPUT);
	MDIO_SetPinDirection(PORTB, 5, OUTPUT);
	MDIO_SetPinDirection(PORTB, 6, OUTPUT);
	MDIO_SetPinDirection(PORTB, 7, OUTPUT);
	MDIO_SetPinDirection(PORTB, 7, OUTPUT);
	return;
} // end initialize8LEDs

void initializeDIP(void) {
	MDIO_SetPinDirection(PORTD, 0, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTD, 1, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTD, 2, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTD, 3, INPUT_PULLUP);
	return;
} // end initializeDIP

void clearLEDs(void) {
	MDIO_SetPinOutput(PORTB, 0, LOW);
	MDIO_SetPinOutput(PORTB, 1, LOW);
	MDIO_SetPinOutput(PORTB, 2, LOW);
	MDIO_SetPinOutput(PORTB, 3, LOW);
	MDIO_SetPinOutput(PORTB, 4, LOW);
	MDIO_SetPinOutput(PORTB, 5, LOW);
	MDIO_SetPinOutput(PORTB, 6, LOW);
	MDIO_SetPinOutput(PORTB, 7, LOW);
	return;
} // end clearLED

void LEDTrain(void) {
	for (uint8 i=0; i<4; i++) {
		if (i==0) {
			MDIO_SetPinOutput(PORTB, 3, LOW);
			MDIO_SetPinOutput(PORTB, 4, LOW);
			MDIO_SetPinOutput(PORTB, i, HIGH);
			MDIO_SetPinOutput(PORTB, 7-i, HIGH);
		}else{
			MDIO_SetPinOutput(PORTB, i-1, LOW);
			MDIO_SetPinOutput(PORTB, 7-i+1, LOW);
			MDIO_SetPinOutput(PORTB, i, HIGH);
			MDIO_SetPinOutput(PORTB, 7-i, HIGH);
		} // end if
		_delay_ms(500);
	} // end for
	for (uint8 i=3; i>0; i--) {
		MDIO_SetPinOutput(PORTB, i, LOW);
		MDIO_SetPinOutput(PORTB, 7-i, LOW);
		MDIO_SetPinOutput(PORTB, i-1, HIGH);
		MDIO_SetPinOutput(PORTB, 7-i+1, HIGH);
		_delay_ms(500);
		} // end for
} // end LEDTrain

int main(void) {
	H7Seg_initialize();
	initialize8LEDs();
	initializeDIP();
	uint8 password = 0;
	while (1) {
		for (uint8 i=0; i<=9; i++) {
			if (MDIO_GetPinValue(PORTD, 0) == password) {
				LEDTrain();
				H7Seg_display(i);
//				_delay_ms(1000);
			}else{
				clearLEDs();
				MDIO_SetPinOutput(PORTB, 0, HIGH);
				MDIO_SetPinOutput(PORTB, 7, HIGH);
				H7Seg_display(0);
			}// end if
		} // end for
	} // end while
	return 0;
} // end main
