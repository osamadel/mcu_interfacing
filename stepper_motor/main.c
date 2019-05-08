#include "libraries/L_STD_TYPES.h"
#include "MCAL/MDIO_interface.h"
#include <util/delay.h>

int main(void) {
	MDIO_SetPinDirection(PORTA, 0, OUTPUT);
	MDIO_SetPinDirection(PORTA, 1, OUTPUT);
	MDIO_SetPinDirection(PORTA, 2, OUTPUT);
	MDIO_SetPinDirection(PORTA, 3, OUTPUT);

	while (1) {
		MDIO_SetPinOutput(PORTA, 0, HIGH);
		MDIO_SetPinOutput(PORTA, 1, LOW);
		MDIO_SetPinOutput(PORTA, 2, LOW);
		MDIO_SetPinOutput(PORTA, 3, LOW);
		_delay_ms(2);

		MDIO_SetPinOutput(PORTA, 0, LOW);
		MDIO_SetPinOutput(PORTA, 1, HIGH);
		MDIO_SetPinOutput(PORTA, 2, LOW);
		MDIO_SetPinOutput(PORTA, 3, LOW);
		_delay_ms(2);

		MDIO_SetPinOutput(PORTA, 0, LOW);
		MDIO_SetPinOutput(PORTA, 1, LOW);
		MDIO_SetPinOutput(PORTA, 2, HIGH);
		MDIO_SetPinOutput(PORTA, 3, LOW);
		_delay_ms(2);

		MDIO_SetPinOutput(PORTA, 0, LOW);
		MDIO_SetPinOutput(PORTA, 1, LOW);
		MDIO_SetPinOutput(PORTA, 2, LOW);
		MDIO_SetPinOutput(PORTA, 3, HIGH);
		_delay_ms(2);
	}

	return 0;
}
