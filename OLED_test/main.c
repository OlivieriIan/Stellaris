#include <stdint.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "rit128x96x4.h"

int main(void)
{
	uint8_t lcd_text[10][30] = {
		"RL-ARM",
		"HTTP example",
		"012345678901234567890",
		"Waiting for DHCP",
		"---------------------",
		"*********************",
		"<<<<<<<<<<<<<<<<<<<<<",
		">>>>>>>>>>>>>>>>>>>>>",
		",,,,,,,,,,,,,,,,,,,,,",
		"....................."
	};

    // Enable OLED module
	RIT128x96x4Init(1000000);
	//RIT128x96x4Clear();
	uint8_t row = 0, fontHeight = 10;
	uint8_t intensity = 10;

	for(row = 0; row < 10; row++)
	{
		RIT128x96x4StringDraw((const char *)&lcd_text[row], 0, row*fontHeight, intensity);
	}

    // Loop forever.
    while(1)
    {
        SysCtlDelay(2000000);
    }
}
