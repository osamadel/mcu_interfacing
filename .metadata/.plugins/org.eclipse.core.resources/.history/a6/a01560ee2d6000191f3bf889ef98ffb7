#ifndef MDIO_INTERFACE_H
#define MDIO_INTERFACE_H
    
    // definitions for pin status
    #define OUTPUT          1
    #define INPUT_FLOAT     2
    #define INPUT_PULLUP    3

    // definitions for pin value
    #define HIGH            1
    #define LOW             0

	// definitions for ports
	#define PORTA 		1
	#define PORTB		2
	#define PORTC		3
	#define PORTD		4

    // prototypes
    void        MDIO_SetPinDirection   (uint8 port, uint8 bitNum, uint8 status);
    void        MDIO_SetPinOutput      (uint8 port, uint8 bitNum, uint8 output);
    uint8      MDIO_GetPinValue       (uint8 port, uint8 bitNum);

#endif
