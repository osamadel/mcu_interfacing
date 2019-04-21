#include "../libraries/L_STD_TYPES.h"
#include "../libraries/L_UTILS.h"
#include "../MCAL/MDIO_interface.h"
#include "HSevenSegments_private.h"
#include "HSevenSegments_interface.h"

void H7Seg_clear(void) {
	MDIO_SetPinOutput(PORTA, 0, HIGH);
	MDIO_SetPinOutput(PORTA, 1, HIGH);
	MDIO_SetPinOutput(PORTA, 2, HIGH);
	MDIO_SetPinOutput(PORTA, 3, HIGH);
	MDIO_SetPinOutput(PORTA, 4, HIGH);
	MDIO_SetPinOutput(PORTA, 5, HIGH);
	MDIO_SetPinOutput(PORTA, 6, HIGH);
	MDIO_SetPinOutput(PORTA, 7, HIGH);
	return;
}

void H7Seg_initialize(void) {
	MDIO_SetPinDirection(PORTA, 0, OUTPUT);
	MDIO_SetPinDirection(PORTA, 1, OUTPUT);
	MDIO_SetPinDirection(PORTA, 2, OUTPUT);
	MDIO_SetPinDirection(PORTA, 3, OUTPUT);
	MDIO_SetPinDirection(PORTA, 4, OUTPUT);
	MDIO_SetPinDirection(PORTA, 5, OUTPUT);
	MDIO_SetPinDirection(PORTA, 6, OUTPUT);
	MDIO_SetPinDirection(PORTA, 7, OUTPUT);

	H7Seg_clear();
	return;
}

void H7Seg_display(uint8 num) {
	H7Seg_clear();
	for (int j=0; numbers[num][j] != -1; j++)
//		PORTA &= ~(0b00000001 << numbers[number][j]);	// Set PORTA bits at numbers to 0
		MDIO_SetPinOutput(PORTA, numbers[num][j], LOW);
	return;
}
