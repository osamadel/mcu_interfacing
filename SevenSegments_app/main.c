#include "libs/L_STD_TYPES.h"
#include "H7Segments_interface.h"
#include <util/delay.h>

int main(void) {
	H7Seg_initialize();

	while (1) {
		for (uint8 i=0; i<=9; i++) {
			H7Seg_display(i);
			_delay_ms(1000);
		} // end for
	} // end while
	return 0;
} // end main
