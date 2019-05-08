#include "../libraries/L_STD_TYPES.h"
#include "../libraries/L_UTILS.h"
#include "../MCAL/MDIO_interface.h"
#include "HNPN_interface.h"


void NPN_ON(uint8 port, uint8 pin)
{
    MDIO_SetPinDirection(port, pin, OUTPUT);
    MDIO_SetPinOutput(port, pin, HIGH);
    return;
}// end NPN_ON


void NPN_OFF(uint8 port, uint8 pin) {
    MDIO_SetPinDirection(port, pin, OUTPUT);
    MDIO_SetPinOutput(port, pin, LOW);
    return;
}// end NPN_OFF
