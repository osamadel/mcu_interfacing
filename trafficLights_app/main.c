#include "libraries/L_STD_TYPES.h"
#include "MCAL/MDIO_interface.h"
#include "HAL/HLCD_interface.h"
#include "HAL/HLED_interface.h"
#include "HAL/HNPN_interface.h"
#include "HAL/HSevenSegments_interface.h"
#include <util/delay.h>

#define RED_LED PORTD, 3
#define YELLOW_LED PORTD, 4
#define GREEN_LED PORTD, 5
#define BUZZER PORTD, 6

void countToZeroWithLED(uint8 ledPort, uint8 pin);
void beepBuzzer(void);


int main(void) {
	// TODO
	HLCD_init(HLCD_8_BIT);
	H7Seg_initialize();
	addLED(RED_LED);
	addLED(YELLOW_LED);
	addLED(GREEN_LED);

	while(1) {

		countToZeroWithLED(RED_LED);
		beepBuzzer();
		countToZeroWithLED(GREEN_LED);
		beepBuzzer();
		HLCD_clear();
		HLCD_setLine(0);
		writeText("I * ITI");
		for (uint8 i=0; i<16; i++)
			HLCD_shiftDisplay(SHIFT_LEFT);
		writeText("Project By");
		HLCD_setLine(1);
		writeText("Osama Adel");
		for (uint8 i=0; i<16; i++)
			HLCD_shiftDisplay(SHIFT_RIGHT);

		for (uint8 i=0; i<16; i++) {
			HLCD_shiftDisplay(SHIFT_LEFT);
			_delay_ms(500);
		}// end for
		for (uint8 i=0; i<16; i++) {
			HLCD_shiftDisplay(SHIFT_RIGHT);
			_delay_ms(500);
		}// end for
		HLCD_clear();
		_delay_ms(1000);

	}
	return 0;
}


void countToZeroWithLED(uint8 ledPort, uint8 pin) {
	// TODO
	LED_OFF(GREEN_LED);
	LED_OFF(YELLOW_LED);
	LED_OFF(RED_LED);

	LED_ON(ledPort, pin);
	for(uint8 i=0; i<10; i++) {
		H7Seg_display(i);
		_delay_ms(1000);
		if (i < 3)
			LED_ON(YELLOW_LED);
	}
	return;
}

void beepBuzzer(void) {
	NPN_ON(BUZZER);
	_delay_ms(1000);
	NPN_OFF(BUZZER);
}
