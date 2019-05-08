#include "../libraries/L_STD_TYPES.h"
#include "../libraries/L_UTILS.h"
#include "MTIMER0_private.h"
#include "MTIMER0_interface.h"
#include "MDIO_interface.h"
#include <util/delay.h>


void MTIMER0_init (uint8 mode, uint32 pScaler) {
	// don't force the output of the compare-match comparator
//	CLR_BIT(TCCR0, 7);

	// enable timer0 overflow interrupt
//	SET_BIT(TIMSK, 0);
//	SET_BIT(TIMSK, 1);
	MDIO_SetPinDirection(PORTB, 3, OUTPUT);
	// enable global interrupts
	SET_BIT(SREG, 7);

	// stop the timer initially
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);

	// switch on the 4 modes of the timer0
	switch (mode) {
	case NORMAL_MODE:
		Mode = NORMAL_MODE;
		CLR_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
		break;
	case PWM_PHASECORRECT_MODE:
		Mode = PWM_PHASECORRECT_MODE;
		SET_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
		break;
	case CTC_MODE:
		Mode = CTC_MODE;
		CLR_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);
		break;
	case FAST_PWM:
		Mode = FAST_PWM;
		SET_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);

		CLR_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		break;
	default:
		break;
	}// end of switch(mode)

	switch (pScaler) {
	case NO_PRESCALE:
		PreScaler = 1;
		prescaler_mask = 1;
		break;
	case PRESCALE_8:
		PreScaler = 8;
		prescaler_mask = 2;
		break;
	case PRESCALE_64:
		PreScaler = 64;
		prescaler_mask = 3;
		break;
	case PRESCALE_256:
		PreScaler = 256;
		prescaler_mask = 4;
		break;
	case PRESCALE_1024:
		PreScaler = 1024;
		prescaler_mask = 5;
		break;
	case EXT_CLK_FALLING:
		// didn't assign a value to PreScaler which
		// may lead to bugs in other regions of the code
		CLR_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
		break;
	case EXT_CLK_RISING:
		// didn't assign a value to PreScaler which
		// may lead to bugs in other regions of the code
		SET_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
		break;
	}

}// end MTIMER0_init

void MTIMER0_start (void) {
	// clear B0-2 then set them equal to PreScaler
	TCCR0 = ((TCCR0 & 0b11111000) | prescaler_mask);
}// end MTIMER0_start

void MTIMER0_stop (void) {
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
	TCNT0 = 0;
}// end MTIMER_stop

void MTIMER0_delay_ms (uint32 delay) {
	switch (Mode) {
	case NORMAL_MODE:
		delay_ms_normal_mode(delay);
		break;
	case PWM_PHASECORRECT_MODE:
		break;
	case CTC_MODE:
		break;
	case FAST_PWM:
		break;
	default:
		break;
	}// end switch(Mode)
}// end MTIMER_delay_ms

void delay_ms_normal_mode(uint32 delay) {
	float32 inputFreq = 0, Tov = 0;
	float32 reminder = 0;
	uint32 Nov = 0; // number of overflows
	inputFreq = CPU_CLK / PreScaler;
	// Tov = tickTime * REG_RESOLUTION = REG_RESOLUTION / inputFreq
	Tov = TCNT0_RESOLUTION / inputFreq;
	// integer number of overflows
	Nov = (delay * 1000.0) / Tov;
	// if there is a reminder, what value of TCNT0 would
	// make that much delay
	reminder = ((delay * 1000.0) / Tov) - Nov;
	if (reminder > 0)
		Nov++;
	else
		reminder = 0;

	TCNT0 = reminder? 255-255*reminder : 0;
	MTIMER0_start();
	while (Nov > 0) {
		// as long as the OV interrupt is not flagged, keep looping
		if(GET_BIT(TIFR, 0))
			// after an OV occurs, decrease the total number of OVs required
			Nov--;


	}

	MTIMER0_stop();

}

void MTIMER0_PWM(uint8 mode, uint8 duty) {
	switch (mode) {
	case NONINVERTED_MODE:
		CLR_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		break;

	case INVERTED_MODE:
		SET_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		break;
	default:
		break;
	}
	OCR0 = duty;
}
