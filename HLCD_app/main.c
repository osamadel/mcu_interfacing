#include "libraries/L_STD_TYPES.h"
#include "HAL/HLCD_interface.h"
#include <util/delay.h>


int main(void) {
	HLCD_init();
	while(1) {
		HLCD_clear();
		HLCD_setLine(1);
		writeText("Osama");
		_delay_ms(1000);
		writeText(" Adel");
		_delay_ms(1000);
		HLCD_setLine(2);
		HLCD_shiftCursor(SHIFT_RIGHT, 2);
		writeText("#Emb SW Eng#");
		_delay_ms(3000);

		for (uint8 i=0; i<16; i++) {
			HLCD_shiftDisplay(SHIFT_RIGHT);
			_delay_ms(500);
		}// end for

		for (uint8 i=0; i<16; i++) {
			HLCD_shiftDisplay(SHIFT_LEFT);
			_delay_ms(500);
		}// end for

	}// end while(1)
	return 0;
}
