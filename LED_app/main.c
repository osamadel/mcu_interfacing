#include "libs/L_STD_TYPES.h"
#include "HLED_interface.h"
#include <util/delay.h>

int main(void) {
	addLED(PORTA, 1);
	while (1) {
		LED_ON(PORTA, 1);
		_delay_ms(1000);
		LED_OFF(PORTA, 1);
		_delay_ms(1000);
	}
	return 0;
}
