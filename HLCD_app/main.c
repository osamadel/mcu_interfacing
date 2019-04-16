#include "libraries/L_STD_TYPES.h"
#include "HAL/HLCD_interface.h"
//#include "MCAL/MDIO_interface.h"
#include <util/delay.h>

void writeText(uint8 * text) {
	for (uint8 i=0; text[i]!='\0'; i++)
		HLCD_writeData(text[i]);
	return;
}

int main(void) {
	HLCD_init();
	while(1) {
		HLCD_clear();
		HLCD_setLine(1);
		writeText("Osama");
		_delay_ms(2000);
		HLCD_setLine(2);
		writeText("Adel");
		_delay_ms(2000);
	}// end while(1)
	return 0;
}
