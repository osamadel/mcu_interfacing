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
//	uint8 name[] = "Osama Adel ";
//	uint8 job[] = "Embedded SW Eng";
	while(1) {
		HLCD_clear();
		writeText("Osama");
		_delay_ms(2000);
//		for (uint8 i=0; name[i]!='\0'; i++)
//			HLCD_writeData(job[i]);
		writeText(" Adel");
		_delay_ms(2000);
	}// end while(1)
	return 0;
}