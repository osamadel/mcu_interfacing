#include "libraries/L_STD_TYPES.h"
#include "MCAL/MDIO_interface.h"
#include "MCAL/MTIMER0_interface.h"
#include <util/delay.h>

int main(void) {
	MDIO_SetPinDirection(PORTA, 0, OUTPUT);
	MDIO_SetPinDirection(PORTA, 1, OUTPUT);
//	MTIMER0_init(FAST_PWM, PRESCALE_64);
//	MTIMER0_start();
//	while (1) {
//		for (uint8 i=255; i>0; i-=5) {
//			MTIMER0_PWM(NONINVERTED_MODE, i);
//			_delay_ms(100);
//		}
//
//		for (uint8 i=255; i>0; i-=5) {
//			MTIMER0_PWM(INVERTED_MODE, i);
//			_delay_ms(100);
//		}
//	}
	while (1)
	{
		MDIO_SetPinOutput(PORTA, 0, HIGH);
		MDIO_SetPinOutput(PORTA, 1, LOW);
		_delay_ms(1000);
		MDIO_SetPinOutput(PORTA, 0, LOW);
		MDIO_SetPinOutput(PORTA, 1, LOW);
		_delay_ms(1000);
		MDIO_SetPinOutput(PORTA, 0, LOW);
		MDIO_SetPinOutput(PORTA, 1, HIGH);
		_delay_ms(1000);
		MDIO_SetPinOutput(PORTA, 0, LOW);
		MDIO_SetPinOutput(PORTA, 1, LOW);
		_delay_ms(1000);
	}
	return 0;
}
