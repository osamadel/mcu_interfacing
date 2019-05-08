#ifndef MTIMER_PRIVATE_H_
#define MTIMER_PRIVATE_H_

	#define TCCR0 		*((volatile uint8 *)(0x53))
	#define TCNT0		*((volatile uint8 *)(0x52))
	#define OCR0		*((volatile uint8 *)(0x5C))
	#define TIMSK		*((volatile uint8 *)(0x59))
	#define TIFR		*((volatile uint8 *)(0x58))
	#define SREG		*((volatile uint8 *)(0x5F))

	#define CPU_CLK		8000000
	#define TCNT0_RESOLUTION	256

	uint16 				PreScaler;
	uint8				prescaler_mask;
	uint8 				Mode;

#endif
