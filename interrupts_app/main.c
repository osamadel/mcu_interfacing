#include "libraries/L_STD_TYPES.h"
// include a lib to call ISR in the vector table
//#include <avr/interrupt.h>
#include <util/delay.h>
#include "MCAL/MDIO_interface.h"
#include "MCAL/MEXTI_interface.h"

void INT0_interrupt(void);
void INT1_interrupt(void);

int main(void) {
	MDIO_SetPinDirection(PORTD, 2, INPUT_PULLUP);
	MDIO_SetPinDirection(PORTD, 3, INPUT_PULLUP);
	MEXTI_enableInterrupt(INT0, MEXTI_FALLING_EDGE);
	MEXTI_enableInterrupt(INT1, MEXTI_FALLING_EDGE);
	MDIO_SetPortDirection(PORTA, 0xFF);

	MEXTI_setCallBack(INT0_interrupt, INT0);
	MEXTI_setCallBack(INT1_interrupt, INT1);

	while (1) {
		// LED train
		for (char i=0; i<8; i++)
		{
//			MDIO_SetPortValue(PORTA, 0);
			(i>0)?MDIO_SetPinOutput(PORTA, i-1, LOW):MDIO_SetPinOutput(PORTA, 7, LOW);
			MDIO_SetPinOutput(PORTA, i, HIGH);
			_delay_ms(1000);
		}
	}
	return 0;
}


void INT0_interrupt(void) {
	// INT0 ISR code
	// all 8 leds ON for 1 sec then OFF
	MDIO_SetPortValue(PORTA, 0xFF);
	_delay_ms(1000);
	MDIO_SetPortValue(PORTA, 0);
	//	_delay_ms(1000);
}


void INT1_interrupt(void) {
	// INT1 ISR code
	volatile static int i = 7;
	(i<7)?MDIO_SetPinOutput(PORTA, i+1, LOW):MDIO_SetPinOutput(PORTA, 0, LOW);
	MDIO_SetPinOutput(PORTA, i, HIGH);
	i = (i==0)?7:i-1;
	//	_delay_ms(1000);
	//	MDIO_SetPortValue(PORTA, 0);
	//	_delay_ms(1000);
}
