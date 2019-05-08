#ifndef M_MEXTI_INTERFACE_H
#define M_EXTI_INTERFACE_H

	#define MEXTI_LOW_LEVEL 		0
	#define MEXTI_LOGIC_CHANGE 		1
	#define MEXTI_FALLING_EDGE 		2
	#define MEXTI_RISING_EDGE 		3
	#define INT0					0
	#define INT1					1
	#define INT2					2

	void MEXTI_enableInterrupt(uint8 intNum, uint8 sensingMode);
	void MEXTI_setCallBack(void (*p) (void), uint8 source);

#endif
