#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

int main(void)
{
	
    // Enable the GPIO module.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlDelay(1);

    // Configure PA1 as an output.
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0); // STATUS LED (LED 2)
    //GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); // Ethernet connector left (green) LED
    //GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3); // Ethernet connector right (orange) LED

    // Loop forever.
    while(1)
    {
        // Set the GPIO high.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 1);
        // Delay for a while.
        SysCtlDelay(1000000);

        // Set the GPIO low.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);

        // Delay for a while.
        SysCtlDelay(1000000);
    }
}
