#include "libraries/L_STD_TYPES.h"
#include "MCAL/MDIO_interface.h"
#include "HAL/HNPN_interface.h"
#include <util/delay.h>


int main(void) {
	while (1) {
		NPN_ON(PORTC, 0);
		_delay_ms(1000);
		NPN_OFF(PORTC, 0);
		_delay_ms(1000);
	}
	return 0;
}
