#include "drivers/libraries/L_STD_TYPES.h"
#include "drivers/MCAL/MDIO_interface.h"
#include "drivers/HAL/HKeyPad_interface.h"
#include "drivers/HAL/HLCD_interface.h"
#include <util/delay.h>

void app1(void) {
	uint8 key;
		MDIO_SetPortDirection(PORTB, 0xFF);
		HKeyPad_init();
		while (1) {
			key = HKeyPad_getKey();
			switch (key) {
			case '1':
			case '7':
				MDIO_SetPortValue(PORTB, 0b00000001);
				break;
			case '2':
			case '8':
				MDIO_SetPortValue(PORTB, 0b00000010);
				break;
			case '3':
			case '9':
				MDIO_SetPortValue(PORTB, 0b00000100);
				break;
			case 'A':
			case 'C':
				MDIO_SetPortValue(PORTB, 0b00001000);
				break;
			case '4':
			case '#':
				MDIO_SetPortValue(PORTB, 0b00010000);
				break;
			case '5':
			case '0':
				MDIO_SetPortValue(PORTB, 0b00100000);
				break;
			case '6':
			case '*':
				MDIO_SetPortValue(PORTB, 0b01000000);
				break;
			case 'B':
			case 'D':
				MDIO_SetPortValue(PORTB, 0b10000000);
				break;
			default:
				MDIO_SetPortValue(PORTB, 0b11111111);

			}// end switch
		}// end while
		return;
}// end app1

void app2(void) {

	// variables definitions
	uint8 cursorCount = 0;
	uint8 key = 0;
	uint8 num1, num2, res;
	num1 = num2 = res = 0;


	// initialization
	HLCD_init();
	HKeyPad_init();
	MDIO_SetPortDirection(PORTB, 0xFF);


	while (1) {
		HLCD_clear();
		HLCD_setLine(1);
		writeText("Enter Number1: ");
		do {
			key = HKeyPad_getKey();
		}while (key == 0);
		_delay_ms(200);
		HLCD_writeData(key);
		_delay_ms(2000);
		num1 = key - 48;

		HLCD_clear();
		writeText("Enter Number2: ");
		do {
			key = HKeyPad_getKey();
		}while (key == 0);
		_delay_ms(200);
		HLCD_writeData(key);
		num2 = key - 48;
		_delay_ms(2000);

		HLCD_clear();
		writeText("Number1 + Number2:");
		HLCD_setLine(2);
		res = num1 + num2;
		HLCD_writeData(res + 48);
		_delay_ms(2000);

		do {
			key = HKeyPad_getKey();
		}while (key == 'C');
	}// end while
	return;
}

int main(void) {
	app2();
	return 0;
}// end main
