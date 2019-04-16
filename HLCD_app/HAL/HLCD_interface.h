#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

	void HLCD_init(void);
	void HLCD_writeCMD(uint8);
	void HLCD_writeData(uint8);
	void HLCD_clear(void);
	void writeText(uint8 * text);
	void HLCD_setLine(uint8 line);

	#define HLCD_FIRST_LINE		1
	#define HLCD_SECOND_LINE	2
	#define HLCD_MODE 			HLCD_4_BIT

#endif
