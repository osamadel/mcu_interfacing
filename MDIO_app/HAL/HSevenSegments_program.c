#include "../libraries/L_STD_TYPES.h"
#include "../libraries/L_UTILS.h"
#include "../MCAL/MDIO_interface.h"
#include "../MCAL/MDIO_private.h"
#include "HSevenSegments_private.h"
#include "HSevenSegments_interface.h"

void H7Seg_clear(void) {
	MDIO_SetPortValue(PORTC, HIGH);
	return;
}

void H7Seg_initialize(void) {
	MDIO_SetPortDirection(PORTC, 0xFF);
	return;
}

void H7Seg_display(uint8 num) {
//	H7Seg_clear();
//	for (uint8 j=0; numbers[num][j] != -1; j++)
	MDIO_SetPortValue(PORTC, numbers[num]);
//		{MDIO_SetPinOutput(PORTC, numbers[num][j], LOW);}
//		MDIO_PORTC &= ~(0b00000001 << numbers[num][j]);	// Set PORTB bits at numbers to 0
//	MDIO_SetPortValue(PORTC, LOW);
	return;
}
