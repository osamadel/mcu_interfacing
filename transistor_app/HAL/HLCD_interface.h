#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

	void HLCD_init						(void);
	void HLCD_clear						(void);
	void HLCD_writeCMD					(uint8);
	void HLCD_writeData					(uint8);
	void HLCD_writeText						(uint8 * text);
	void HLCD_setLine					(uint8 line);
	void HLCD_shiftDisplay				(uint8 direction);
	void HLCD_shiftCursor				(uint8 direction, uint8 steps);

	#define HLCD_FIRST_LINE		1
	#define HLCD_SECOND_LINE	2
	#define HLCD_MODE 			HLCD_4_BIT
	#define SHIFT_LEFT			1
	#define SHIFT_RIGHT			2

#endif
