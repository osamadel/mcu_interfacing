#include "../libraries/L_STD_TYPES.h"
#include "../MCAL/MDIO_interface.h"
#include "HLCD_private.h"
#include "HLCD_interface.h"
#include <util/delay.h>




void writeText(uint8 * text) {
	for (uint8 i=0; text[i]!='\0'; i++)
		HLCD_writeData(text[i]);
	return;
}




void HLCD_clear(void) {
	HLCD_writeCMD(0b00000001);
	return;
}// end HLCD_clear




void HLCD_setLine(uint8 line) {
	if (line <= 2 && line > 0) {
		if (line == 1)
			HLCD_writeCMD(0b10000000);
		else
			HLCD_writeCMD(0b11000000);
	}
	return;
}// end setLine




void HLCD_shiftDisplay(uint8 direction) {
	if (direction == SHIFT_LEFT)
		HLCD_writeCMD(0b00011000);
	else if (direction == SHIFT_RIGHT)
		HLCD_writeCMD(0b00011100);
	return;
}// end HLCD_shiftDisplay



void HLCD_shiftCursor(uint8 direction, uint8 steps) {
	if (direction == SHIFT_LEFT)
		for (uint8 i=0; i<steps; i++)
			HLCD_writeCMD(0b00010000);
	else if (direction == SHIFT_RIGHT)
		for (uint8 i=0; i<steps; i++)
			HLCD_writeCMD(0b00010100);
	return;
}// end




void HLCD_init(void) {
	// set PORTA as OUTPUT
#if HLCD_MODE == HLCD_8_BIT
	MDIO_SetPinDirection(HLCD_D0, OUTPUT);
	MDIO_SetPinDirection(HLCD_D1, OUTPUT);
	MDIO_SetPinDirection(HLCD_D2, OUTPUT);
	MDIO_SetPinDirection(HLCD_D3, OUTPUT);
#endif
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
#if HLCD_MODE == HLCD_8_BIT
	HLCD_writeCMD(0b00111100); // set LCD to 8-bit mode, 2 lines, 5x10 font size
#else
	HLCD_writeCMD(0b00101100); // set LCD to 4-bit mode, 2 lines, 5x10 font size
#endif
	_delay_ms(1);
	HLCD_writeCMD(0b00001111); // set LCD display ON, cursor ON, cursor blink ON
	_delay_ms(1);
	HLCD_writeCMD(0b00000001); // clear LCD display
	_delay_ms(2);
	HLCD_writeCMD(0b00000110); // set Address Counter to increasing, NO display shift
	return;
}// end HLCD_init




#if HLCD_MODE == HLCD_8_BIT
/*LCD in 8-bit mode*/
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



#else if HLCD_MODE == HLCD_4_BIT
/*LCD in 4-bit mode*/
void HLCD_writeCMD(uint8 cmd) {
	MDIO_SetPinOutput(HLCD_RS, LOW);		// set RS to 0 (Command Reg)
	MDIO_SetPinOutput(HLCD_RW, LOW);		// Set RW to 0

	uint8 H = cmd & 0xF0;
	uint8 L = (cmd & 0x0F) << 4;

	MDIO_SetPortValue(HLCD_8PINS, H);		// Write the command to D4-D7
	MDIO_SetPinOutput(HLCD_E, HIGH);		// Set E to 1 (Read Data)
	_delay_ms(2);							// delay 2ms
	MDIO_SetPinOutput(HLCD_E, LOW);			// Set E to 0 (falling edge: Write Data)

	MDIO_SetPortValue(HLCD_8PINS, L);		// Write the command to D4-D7
	MDIO_SetPinOutput(HLCD_E, HIGH);		// Set E to 1 (Read Data)
	_delay_ms(2);							// delay 2ms
	MDIO_SetPinOutput(HLCD_E, LOW);			// Set E to 0 (falling edge: Write Data)

	return;
}// end HLCD_writeCMD




void HLCD_writeData(uint8 data) {
	MDIO_SetPinOutput(HLCD_RS, HIGH);		// set RS to 1 (Data Reg)
	MDIO_SetPinOutput(HLCD_RW, LOW); 		// Set RW to 0

	uint8 H = data & 0xF0;
	uint8 L = (data & 0x0F) << 4;

	MDIO_SetPortValue(HLCD_8PINS, H);	// Write the data to D0-D7
	MDIO_SetPinOutput(HLCD_E, HIGH); 		// Set E to 1 (Read Data)
	_delay_ms(2);							// delay 2ms
	MDIO_SetPinOutput(HLCD_E, LOW); 		// Set E to 0 (falling edge: Write Data)

	MDIO_SetPortValue(HLCD_8PINS, L);	// Write the data to D0-D7
	MDIO_SetPinOutput(HLCD_E, HIGH); 		// Set E to 1 (Read Data)
	_delay_ms(2);							// delay 2ms
	MDIO_SetPinOutput(HLCD_E, LOW); 		// Set E to 0 (falling edge: Write Data)
	return;
}// end HLCD_writeData


#endif
