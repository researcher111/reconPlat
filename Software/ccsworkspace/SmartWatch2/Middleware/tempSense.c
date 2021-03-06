/*
 * tempSense.c
 *
 *  Author: Daniel
 */

#include <msp430.h>

long tempSense()
{
	unsigned long degrees;
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_10 + ADC10DIV_0;
	ADC10CTL0 = SREF_1 + ADC10SHT_3 + REFON + ADC10ON + ADC10IE;
	// Range to VRef+, Max Sample and hold time
	// turn on reference, turn on the ADC and enable Interrupts
	__delay_cycles(40); // Allow time for the reference voltage to settle
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);
	degrees = ADC10MEM - 673; //deference the pointer and modify the memmory
	degrees *= 4230;
	degrees /= 1024;
	return degrees;
}

