/* the following includes must be in this order:
 * types, utilities, private data, interface prototypes */
#include "../libs/L_STD_TYPES.h"
#include "../libs/L_UTILS.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

void MDIO_SetPinDirection (uint8 port, uint8 bitNum, uint8 status) {
    // TODO: switch on port
	switch (port) {
	// ********************* PORTA ****************************
	case PORTA:
		switch (status) {
		case OUTPUT:
			SET_BIT(MDIO_DDRA, bitNum);				// set DDRA bitNum to 1
			break;
		case INPUT_FLOAT:
			CLR_BIT(MDIO_DDRA, bitNum);				// set DDRA bitNum to 0
			break;
		case INPUT_PULLUP:
			CLR_BIT(MDIO_DDRA, bitNum);				// set DDRA bitNum to 0
			SET_BIT(MDIO_PORTA, bitNum);			// set PORTA bitNum to 1
			break;
		default:
			break;
		} // end switch(status)
		break;
	// ********************* PORTB ****************************
	case PORTB:
		switch (status) {
		case OUTPUT:
			SET_BIT(MDIO_DDRB, bitNum);				// set DDRB bitNum to 1
			break;
		case INPUT_FLOAT:
			CLR_BIT(MDIO_DDRB, bitNum);				// set DDRB bitNum to 0
			break;
		case INPUT_PULLUP:
			CLR_BIT(MDIO_DDRB, bitNum);				// set DDRB bitNum to 0
			SET_BIT(MDIO_PORTB, bitNum);			// set PORTB bitNum to 1
			break;
		default:
			break;
		} // end switch(status)
		break;
	// ********************* PORTC ****************************
	case PORTC:
		switch (status) {
		case OUTPUT:
			SET_BIT(MDIO_DDRC, bitNum);				// set DDRC bitNum to 1
			break;
		case INPUT_FLOAT:
			CLR_BIT(MDIO_DDRC, bitNum);				// set DDRC bitNum to 0
			break;
		case INPUT_PULLUP:
			CLR_BIT(MDIO_DDRC, bitNum);				// set DDRC bitNum to 0
			SET_BIT(MDIO_PORTC, bitNum);			// set PORTC bitNum to 1
			break;
		default:
			break;
		} // end switch(status)
		break;
	// ********************* PORTD ****************************
	case PORTD:
		switch (status) {
		case OUTPUT:
			SET_BIT(MDIO_DDRD, bitNum);				// set DDRD bitNum to 1
			break;
		case INPUT_FLOAT:
			CLR_BIT(MDIO_DDRD, bitNum);				// set DDRD bitNum to 0
			break;
		case INPUT_PULLUP:
			CLR_BIT(MDIO_DDRD, bitNum);				// set DDRD bitNum to 0
			SET_BIT(MDIO_PORTD, bitNum);			// set PORTD bitNum to 1
			break;
		default:
			break;
		} // end switch(status)
		break;
	} // end switch(port)

	return;
} // end MDIO_SetPinDirection

void MDIO_SetPinOutput (uint8 port, uint8 bitNum, uint8 output) {
    // TODO
	switch (port) {
	case PORTA:
		if (output) SET_BIT(MDIO_PORTA, bitNum);
		else 		CLR_BIT(MDIO_PORTA, bitNum);
		break;
	case PORTB:
		if (output) SET_BIT(MDIO_PORTB, bitNum);
		else 		CLR_BIT(MDIO_PORTB, bitNum);
		break;
	case PORTC:
		if (output) SET_BIT(MDIO_PORTC, bitNum);
		else 		CLR_BIT(MDIO_PORTC, bitNum);
		break;
	case PORTD:
		if (output) SET_BIT(MDIO_PORTD, bitNum);
		else 		CLR_BIT(MDIO_PORTD, bitNum);
		break;
	default:
		break;
	} // end switch(port)
	return;
} // end MDIO_SetPinOutput


uint8 MDIO_GetPinValue (uint8 port, uint8 bitNum) {
    // TODO
	uint8 val;
	switch (port) {
	case PORTA:
		val = GET_BIT(MDIO_PINA, bitNum);
		break;
	case PORTB:
		val = GET_BIT(MDIO_PINB, bitNum);
		break;
	case PORTC:
		val = GET_BIT(MDIO_PINC, bitNum);
		break;
	case PORTD:
		val = GET_BIT(MDIO_PIND, bitNum);
		break;
	default:
		val = 0xff;
	} // end switch(port)
	return val;
} // end MDIO_GetPinValue
