#include "../libraries/L_STD_TYPES.h"
#include "../libraries/L_UTILS.h"
//#include <avr/interrupt.h>
#include "MEXTI_private.h"
#include "MEXTI_interface.h"



void MEXTI_setCallBack(void (*p) (void), uint8 source) {
	switch (source){
	case INT0:
		int0_func = p;
		break;
	case INT1:
		int1_func = p;
		break;
	case INT2:
		int2_func = p;
		break;
	default:
		break;
	}

}

void MEXTI_enableInterrupt(uint8 intNum, uint8 sensingMode) {
	SET_BIT(MEXTI_SREG, 7);
	switch (intNum) {
	case INT0:
		SET_BIT(MEXTI_GICR, 6);
		switch (sensingMode) {
		case MEXTI_LOW_LEVEL:
			CLR_BIT(MEXTI_MCUCR, 1);
			CLR_BIT(MEXTI_MCUCR, 0);
			break;
		case MEXTI_LOGIC_CHANGE:
			CLR_BIT(MEXTI_MCUCR, 1);
			SET_BIT(MEXTI_MCUCR, 0);
			break;
		case MEXTI_FALLING_EDGE:
			SET_BIT(MEXTI_MCUCR, 1);
			CLR_BIT(MEXTI_MCUCR, 0);
			break;
		case MEXTI_RISING_EDGE:
			SET_BIT(MEXTI_MCUCR, 1);
			SET_BIT(MEXTI_MCUCR, 0);
			break;
		default:
			break;
		}// end switch(sensingMode)
		break;
	case INT1:
		SET_BIT(MEXTI_GICR, 7);
		switch (sensingMode) {
		case MEXTI_LOW_LEVEL:
			CLR_BIT(MEXTI_MCUCR, 3);
			CLR_BIT(MEXTI_MCUCR, 2);
			break;
		case MEXTI_LOGIC_CHANGE:
			CLR_BIT(MEXTI_MCUCR, 3);
			SET_BIT(MEXTI_MCUCR, 2);
			break;
		case MEXTI_FALLING_EDGE:
			SET_BIT(MEXTI_MCUCR, 3);
			CLR_BIT(MEXTI_MCUCR, 2);
			break;
		case MEXTI_RISING_EDGE:
			SET_BIT(MEXTI_MCUCR, 3);
			SET_BIT(MEXTI_MCUCR, 2);
			break;
		default:
			break;
		}// end switch(sensingMode)
		break;
	case INT2:
		SET_BIT(MEXTI_GICR, 5);
		switch (sensingMode) {
		case MEXTI_FALLING_EDGE:
			CLR_BIT(MEXTI_MCUCSR, 6);
			break;
		case MEXTI_RISING_EDGE:
			SET_BIT(MEXTI_MCUCSR, 6);
			break;
		default:
			break;
		}// end switch(sensingMode)
		break;
	default:
		break;
	}
}




void __vector_1(void) {
	int0_func();
}


void __vector_2(void) {
	int1_func();
}

//ISR(INT0_vect) {
//}
//
//ISR(INT1_vect) {
//	int1_func();
//}
