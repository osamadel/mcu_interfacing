#include "../libraries/L_STD_TYPES.h"
#include "../MCAL/MDIO_interface.h"
#include "HLCD_private.h"
#include "HLCD_interface.h"
#include <util/delay.h>

#if HLCD_MODE == HLCD_8_BIT
/*LCD in 8-bit mode*/
void HLCD_init(void) {
	// set PORTA as OUTPUT
	MDIO_SetPinDirection(HLCD_D0, OUTPUT);
	MDIO_SetPinDirection(HLCD_D1, OUTPUT);
	MDIO_SetPinDirection(HLCD_D2, OUTPUT);
	MDIO_SetPinDirection(HLCD_D3, OUTPUT);
	MDIO_SetPinDirection(HLCD_D4, OUTPUT);
	MDIO_SetPinDirection(HLCD_D5, OUTPUT);
	MDIO_SetPinDirection(HLCD_D6, OUTPUT);
	MDIO_SetPinDirection(HLCD_D7, OUTPUT);
	// set RW as OUTPUT
	MDIO_SetPinDirection(HLCD_RW, OUTPUT);
	// set RS as OUTPUT
	MDIO_SetPinDirection(HLCD_RS, OUTPUT);
	// set E as OUTPUT
	MDIO_SetPinDirection(HLCD_E, OUTPUT);
	// set E to (0)
	MDIO_SetPinOutput(HLCD_E, LOW);
	_delay_ms(50);

	HLCD_writeCMD(0b00111100); // set LCD to 8-bit mode, 2 lines, 5x10 font size
	_delay_ms(1);
	HLCD_writeCMD(0b00001111); // set LCD display ON, cursor ON, cursor blink ON
	_delay_ms(1);
	HLCD_writeCMD(0b00000001); // clear LCD display
	_delay_ms(2);
	HLCD_writeCMD(0b00000110); // set Address Counter to increasing, NO display shift
	return;
}// end HLCD_init

void HLCD_writeCMD(uint8 cmd) {
	MDIO_SetPinOutput(HLCD_RS, LOW);		// set RS to 0 (Command Reg)
	MDIO_SetPinOutput(HLCD_RW, LOW);		// Set RW to 0
	MDIO_SetPortValue(HLCD_8PINS, cmd);		// Write the command to D0-D7
	MDIO_SetPinOutput(HLCD_E, HIGH);		// Set E to 1 (Read Data)
	_delay_ms(2);							// delay 2ms
	MDIO_SetPinOutput(HLCD_E, LOW);			// Set E to 0 (falling edge: Write Data)
	return;
}// end HLCD_writeCMD

void HLCD_writeData(uint8 data) {
	MDIO_SetPinOutput(HLCD_RS, HIGH);		// set RS to 1 (Data Reg)
	MDIO_SetPinOutput(HLCD_RW, LOW); 		// Set RW to 0
	MDIO_SetPortValue(HLCD_8PINS, data);	// Write the data to D0-D7
	MDIO_SetPinOutput(HLCD_E, HIGH); 		// Set E to 1 (Read Data)
	_delay_ms(2);							// delay 2ms
	MDIO_SetPinOutput(HLCD_E, LOW); 		// Set E to 0 (falling edge: Write Data)
	return;
}// end HLCD_writeData

void HLCD_clear(void) {
	HLCD_writeCMD(0b00000001);
	return;
}// end HLCD_clear

#else if HLCD_MODE == HLCD_4_BIT
// LCD in 4-bit mode

void HLCD_init(void) {
	// set PORTA as OUTPUT
	MDIO_SetPinDirection(HLCD_D0, OUTPUT);
	MDIO_SetPinDirection(HLCD_D1, OUTPUT);
	MDIO_SetPinDirection(HLCD_D2, OUTPUT);
	MDIO_SetPinDirection(HLCD_D3, OUTPUT);
	MDIO_SetPinDirection(HLCD_D4, OUTPUT);
	MDIO_SetPinDirection(HLCD_D5, OUTPUT);
	MDIO_SetPinDirection(HLCD_D6, OUTPUT);
	MDIO_SetPinDirection(HLCD_D7, OUTPUT);
	// set RW as OUTPUT
	MDIO_SetPinDirection(HLCD_RW, OUTPUT);
	// set RS as OUTPUT
	MDIO_SetPinDirection(HLCD_RS, OUTPUT);
	// set E as OUTPUT
	MDIO_SetPinDirection(HLCD_E, OUTPUT);
	// set E to (0)
	MDIO_SetPinOutput(HLCD_E, LOW);
	_delay_ms(50);
	HLCD_writeCMD(0b00101100); // set LCD to 8-bit mode, 2 lines, 5x10 font size
	_delay_ms(1);
	HLCD_writeCMD(0b00001111); // set LCD display ON, cursor ON, cursor blink ON
	_delay_ms(1);
	HLCD_writeCMD(0b00000001); // clear LCD display
	_delay_ms(2);
	HLCD_writeCMD(0b00000110); // set Address Counter to increasing, NO display shift

	return;
}// end HLCD_init

void HLCD_writeCMD(uint8 cmd) {
	return;
}// end HLCD_writeCMD

void HLCD_writeData(uint8 data) {
	return;
}// end HLCD_writeData

#endif
