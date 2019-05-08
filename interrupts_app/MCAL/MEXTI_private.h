#ifndef M_MEXTI_PRIVATE_H
#define M_EXTI_PRIVATE_H

	#define MEXTI_SREG 		*((volatile uint8 *) 0x5F)
	#define MEXTI_MCUCR 	*((volatile uint8 *) 0x55)
	#define MEXTI_MCUCSR 	*((volatile uint8 *) 0x54)
	#define MEXTI_GICR 		*((volatile uint8 *) 0x5B)
	#define MEXTI_GIFR	 	*((volatile uint8 *) 0x5A)

	void (* int0_func) (void);
	void (* int1_func) (void);
	void (* int2_func) (void);

	void __vector_1(void) __attribute__((signal, INTR_ATTRS));
	void __vector_2(void) __attribute__((signal, INTR_ATTRS));
	void __vector_3(void) __attribute__((signal, INTR_ATTRS));

#endif
