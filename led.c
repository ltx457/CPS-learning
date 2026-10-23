#include "led.h"
#include <xc.h>

void led_init(void){
	CLEARBIT(LED1_TRIS); // set Pin to Output
	Nop();
	CLEARBIT(LED2_TRIS); // set Pin to Output
	Nop();
	CLEARBIT(LED3_TRIS); // set Pin to Output
	Nop();
	CLEARBIT(LED4_TRIS); // set Pin to Output
	Nop();
	CLEARBIT(LED5_TRIS); // set Pin to Output
	Nop();
}
void led_display_binary(unsigned int counter)
{
    unsigned int value = counter & 0x1FU;

    unsigned int bit0 = (value >> 0) & 1U;
    unsigned int bit1 = (value >> 1) & 1U;
    unsigned int bit2 = (value >> 2) & 1U;
    unsigned int bit3 = (value >> 3) & 1U;
    unsigned int bit4 = (value >> 4) & 1U;

    LED1_PORT = bit0;
    LED2_PORT = bit1;
    LED3_PORT = bit2;
    LED4_PORT = bit3;
    LED5_PORT = bit4;
}

    // Connect these bits to the actual
    // LED output registers from led.h.

