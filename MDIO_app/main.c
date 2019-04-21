#include "libraries/L_STD_TYPES.h"
#include "MCAL/MDIO_interface.h"
#include "HAL/HSevenSegments_interface.h"
#include <util/delay.h>


int main(void) {
	MDIO_SetPinDirection(PORTB, 0, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTB, 1, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTB, 2, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTB, 3, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTB, 4, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTB, 5, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTB, 6, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTB, 7, INPUT_PULLUP);
	H7Seg_initialize();

	while (1) {
		uint8 switches1 = MDIO_GetPinValue(PORTB, 0);
		uint8 switches2 = MDIO_GetPinValue(PORTB, 1);
		if (switches1 == 0)
			H7Seg_display(0);
		else if(switches2 == 0)
			H7Seg_display(1);
		else
			H7Seg_display(6);

	}



	return 0;
} // end main
