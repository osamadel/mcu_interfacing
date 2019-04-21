#ifndef HLED_INTERFACE_H
#define HLED_INTERFACE_H
#include "../MCAL/MDIO_interface.h"

	void addLED(uint8 port, uint8 bit);
	void LED_ON(uint8 port, uint8 bit);
	void LED_OFF(uint8 port, uint8 bit);

#endif
