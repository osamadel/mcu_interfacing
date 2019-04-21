#include "../libraries/L_STD_TYPES.h"
#include "../libraries/L_UTILS.h"
#include "../MCAL/MDIO_interface.h"
#include "HSevenSegments_private.h"
#include "HSevenSegments_interface.h"

void H7Seg_clear(void) {
	MDIO_SetPinOutput(PORTB, 0, HIGH);
	MDIO_SetPinOutput(PORTB, 1, HIGH);
	MDIO_SetPinOutput(PORTB, 2, HIGH);
	MDIO_SetPinOutput(PORTB, 3, HIGH);
	MDIO_SetPinOutput(PORTB, 4, HIGH);
	MDIO_SetPinOutput(PORTB, 5, HIGH);
	MDIO_SetPinOutput(PORTB, 6, HIGH);
	MDIO_SetPinOutput(PORTB, 7, HIGH);
	return;
}

void H7Seg_initialize(void) {
	MDIO_SetPinDirection(PORTB, 0, OUTPUT);
	MDIO_SetPinDirection(PORTB, 1, OUTPUT);
	MDIO_SetPinDirection(PORTB, 2, OUTPUT);
	MDIO_SetPinDirection(PORTB, 3, OUTPUT);
	MDIO_SetPinDirection(PORTB, 4, OUTPUT);
	MDIO_SetPinDirection(PORTB, 5, OUTPUT);
	MDIO_SetPinDirection(PORTB, 6, OUTPUT);
	MDIO_SetPinDirection(PORTB, 7, OUTPUT);

	H7Seg_clear();
	return;
}

void H7Seg_display(uint8 num) {
	H7Seg_clear();
	for (int j=0; numbers[num][j] != -1; j++)
//		PORTB &= ~(0b00000001 << numbers[number][j]);	// Set PORTB bits at numbers to 0
		MDIO_SetPinOutput(PORTB, numbers[num][j], LOW);
	return;
}
