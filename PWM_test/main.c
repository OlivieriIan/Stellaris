
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"

/*
 * Drive the status led PF0 (PWM0) from 0 to 100% duty cycle continuously every ~4 seconds
 */

int main(void)
{
    unsigned long period = 0, dutyCycle = 0, dutyCycleDelta = 0;

    // Set the clocking to run directly from the crystal.
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);
    SysCtlPWMClockSet(SYSCTL_PWMDIV_1);

    // Enable the peripherals used by this example.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); // Enable PWM
    //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD); // Enable GPIO Port D
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Enable GPIO Port F

    // Set GPIO F0 and D1 as PWM pins.  They are used to output the PWM0 and
    // PWM1 signals.
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_0); // PF0 / PWM0 (LED)
    //GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_1); // PD1 / PWM1 (Buzzer)

    // Compute the PWM period based on the system clock.
    period = SysCtlClockGet() / 1000; // 1KHz

    // Set the PWM period to .
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, period);

    // Set PWM0 to a duty cycle of 25% and PWM1 to a duty cycle of 75%.
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, dutyCycle);
    //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, period / 2);

    // Enable the PWM0 and PWM1 output signals.
    //PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT, true);
    // Enable the PWM0 output signals.
    PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, 1);

    // Enable the PWM generator.
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);

    // Loop forever while the PWM signals are generated.
    dutyCycleDelta = period/100;
    while(1)
    {
        SysCtlDelay(100000);
        dutyCycle += dutyCycleDelta;
        if (dutyCycle > period) {
        	dutyCycle = 0;
        }
        PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, dutyCycle);
    }
}
