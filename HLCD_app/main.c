#include "libraries/L_STD_TYPES.h"
#include "HAL/HLCD_interface.h"
#include <util/delay.h>


void init_charachter(void) {
	uint8 character[] = {
			0b00011111,
			0b00011111,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00011111,
			0b00000000
	};
	HLCD_writeCMD(0x40);
	for (uint8 i=0; i<8; i++)
		HLCD_writeData(character[i]);
	HLCD_writeCMD(0x80);
	return;
}


int main(void) {
	HLCD_init(HLCD_4_BIT);
	init_charachter();
	while(1) {
		HLCD_clear();
		HLCD_setLine(0);
		HLCD_writeData(0x00);
		_delay_ms(1000);
		writeText("Osama");
		_delay_ms(1000);
		writeText(" Adel");
		_delay_ms(1000);
		HLCD_setLine(1);
		HLCD_shiftCursor(SHIFT_RIGHT, 2);
		writeText("Embedded Engineer");
		_delay_ms(3000);

		/*for (uint8 i=0; i<16; i++) {
			HLCD_shiftDisplay(SHIFT_LEFT);
			_delay_ms(500);
		}// end for

		for (uint8 i=0; i<16; i++) {
			HLCD_shiftDisplay(SHIFT_RIGHT);
			_delay_ms(500);
		}// end for*/

	}// end while(1)
	return 0;
}
