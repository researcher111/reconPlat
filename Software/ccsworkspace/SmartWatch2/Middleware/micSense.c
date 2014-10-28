/*
 * mic.c
 *
 *  Created on: Oct 9, 2014
 *      Author: Daniel
 */
#include <msp430.h>


long micSense()
{
	ADC10CTL0 &= ~ENC;							// Switch off ADC.. (Can't set if enabled)
	ADC10CTL1 = INCH_4 + ADC10DIV_0;
	ADC10CTL0 = SREF_1 + ADC10SHT_3 + ADC10ON + ADC10IE;
												// Range to 2.5V reference, Max Sample and hold time
												// turn on reference, turn on the ADC and enable Interrupts
	__delay_cycles(140); 							// Allow time for the reference voltage to settle
	ADC10CTL0 |= ENC + ADC10SC;					// enable the encoder and start conversion
	__bis_SR_register(CPUOFF + GIE);			// Turn off the CPU and allow interrupts (ISR turns on CPU)
	return ADC10MEM;


}
