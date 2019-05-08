#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_

	#define NORMAL_MODE 					0
	#define PWM_PHASECORRECT_MODE 			1
	#define CTC_MODE 						2
	#define FAST_PWM 						3

	#define NO_PRESCALE 					0
	#define PRESCALE_8 						1
	#define PRESCALE_64 					2
	#define PRESCALE_256 					3
	#define PRESCALE_1024 					4
	#define EXT_CLK_FALLING 				5
	#define EXT_CLK_RISING 					6

	#define CTC_NORMAL						0
	#define CTC_TOGGLE						1
	#define CTC_SET							2
	#define CTC_CLR							3

	#define INVERTED_MODE		 			0
	#define NONINVERTED_MODE 				1


	void MTIMER0_init						(uint8 mode, uint32 pScaler);
	void MTIMER0_start						(void);
	void MTIMER0_stop						(void);
	void MTIMER0_delay_ms					(uint32 delay);
	void delay_ms_normal_mode				(uint32 delay);
	void MTIMER0_PWM						(uint8 mode, uint8 duty);


#endif
