#ifndef H7SEGMENTS_PRIVATE_H
#define H7SEGMENTS_PRIVATE_H

	enum segment {A, B, C, D, E, F, G};
//	unsigned int numbers[11][8] = {
//			{A,B,C,D,E,F,-1},		// 0
//			{B,C,-1},				// 1
//			{A,B,E,D,G,-1},			// 2
//			{A,B,C,D,G,-1},			// 3
//			{B,C,F,G,-1},			// 4
//			{A,C,D,F,G,-1},			// 5
//			{A,C,D,E,F,G,-1},		// 6
//			{A,B,C,-1},				// 7
//			{A,B,C,D,E,F,G,-1}, 	// 8
//			{A,B,C,D,F,G,-1},		// 9
//			{E,F}
//	};
	uint8 numbers[10] = {
			0b01000000,
			0b01111001,
			0b00100100,
			0b00110000,
			0b00011001,
			0b00010010,
			0b00000010,
			0b01111000,
			0b00000000,
			0b00010000
	};
//	uint8 numbers[10] = {
//			0b01111110,
//			0b10111110,
//			0b11011110,
//			0b11101110,
//			0b11110110,
//			0b11111010,
//			0b11111100,
//			0b10101010,
//			0b01010100,
//			0b00000010
//	};

#endif
