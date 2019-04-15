#include "libs/L_STD_TYPES.h"
#include "libs/L_UTILS.h"
#include "MDIO/MDIO_interface.h"

void addLED(port, bit) {
	MDIO_SetPinDirection(port, bit, OUTPUT);
}
void LED_ON(port, bit) {
	MDIO_SetPinOutput(port, bit, HIGH);
}
void LED_OFF(port, bit) {
	MDIO_SetPinOutput(port, bit, LOW);
}
