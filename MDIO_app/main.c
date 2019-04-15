#include "L_STD_TYPES.h"
#include "MDIO_interface.h"
#include <util/delay.h>
int main(void) {

	MDIO_SetPinDirection(PORTA, 0, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTA, 1, OUTPUT);
	uint_8 sw;
	while ( 1 ) {
		sw = MDIO_GetPinValue(PORTA, 1);
		if (sw == 0) {
			MDIO_SetPinOutput(PORTA, 1, HIGH);
			_delay_ms(500);
			MDIO_SetPinOutput(PORTA, 1, LOW);
			_delay_ms(500);
		}else
			MDIO_SetPinOutput(PORTA, 1, LOW);
		// end if

	}// end while(1)

	return 0;
} // end main
