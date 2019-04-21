#include "libraries/L_STD_TYPES.h"
#include "libraries/L_UTILS.h"
#include "MCAL/MDIO_interface.h"
#include "HAL/HLED_interface.h"
#include "HAL/HSevenSegments_interface.h"
#include "HAL/HLCD_interface.h"
#include "HAL/HNPN_interface.h"
#include <util/delay.h>

#define RED_LED PORTD, 3
#define YELLOW_LED PORTD, 4
#define GREEN_LED PORTD, 5
#define BUZZER PORTD, 6

void countToZeroWithLED (uint8 ledPort, uint8 pin);
void beepBuzzer (void);


int main(void) {
	// TODO
	HLCD_init(HLCD_8_BIT);
	HLCD_init_character();
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
		HLCD_setCursor(0, 0);
		HLCD_writeText("I ");
		HLCD_writeData(0x00);	// write the special new character
		HLCD_writeText(" ITI");
		_delay_ms(1000);

		HLCD_setCursor(0, 16);
		HLCD_writeText("Project By");
		HLCD_setCursor(1, 16);
		HLCD_writeText("Osama Adel");
		_delay_ms(1000);

		for (uint8 i=0; i<16; i++) {
			HLCD_shiftDisplay(SHIFT_LEFT);
			_delay_ms(500);
		}// end for
		_delay_ms(1000);
		for (uint8 i=0; i<16; i++) {
			HLCD_shiftDisplay(SHIFT_RIGHT);
			_delay_ms(500);
		}// end for
		_delay_ms(1000);
		HLCD_clear();

	}
	return 0;
}


void countToZeroWithLED(uint8 ledPort, uint8 pin) {
	// TODO
	LED_ON(ledPort, pin);
	for(int i=9; i>=0; i--) {
		H7Seg_display(i);
		if (i < 3)
			LED_ON(YELLOW_LED);
		_delay_ms(1000);
	}
	LED_OFF(GREEN_LED);
	LED_OFF(YELLOW_LED);
	LED_OFF(RED_LED);
	return;
}

void beepBuzzer(void) {
	NPN_ON(BUZZER);
	_delay_ms(1000);
	NPN_OFF(BUZZER);
}
