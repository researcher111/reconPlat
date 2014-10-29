#include <msp430.h>
#include <LCD.h>
#include <tempSense.h>
#include <helpers.h>
#include <lightSense.h>
#include <micSense.h>


void main(void) {
	unsigned long volts;
	unsigned long lux;
	unsigned long degrees;
	char* reading;
	board_init();
	LCD_init();
	uart_init();
	while(1) {
/*	**************************************************************************
*	Write out the Temperature ADC Values*/
		LCD_gotoXY(0,0);
		LCD_writeString("AT:");
		degrees = tempSense();
		LCD_writeChar('(');
		reading = convertADC(degrees,1);
		LCD_writeString(reading);
		LCD_writeChar(0x7f);
		LCD_writeString("C)");



/*	**************************************************************************
*	Write out the  ADC Values Light sensor (Pin 1.3)
*
*/
		LCD_gotoXY(0,2);
		LCD_writeString("LR:");
		LCD_gotoXY(28,2);							// Move to next line
		LCD_writeChar('(');
		lux = lightSense();
		LCD_writeString(convertADC(lux,100));
		LCD_writeString("V)");


/*	**************************************************************************
*	Write out the MIC ADC Values (Pin 1.4)
*
*/
		LCD_gotoXY(0,4);							// Move to next line
		LCD_writeString("MIC:  ");
		LCD_writeString(convertADC(micSense(),-1));



/*	**************************************************************************
*	Write out the Sensing Module values ADC Values (Pin 1.6)
*
*/
		LCD_gotoXY(0,5);							// Move to next line
		LCD_writeString("IR:  ");
		long valueSense = moduleSense();
		if( valueSense < 1020){ // Detected IR pulse
			LCD_writeString("Signal");
			__enable_interrupt();
			uart_puts(reading);
			unsigned char c = uart_getc(); // Get convermation to progress.
		}else{
			LCD_writeString("NO Signal");

		}




		//	__enable_interrupt();
		//uart_puts(reading);
		//unsigned char c = uart_getc(); // Get convermation to progress.
		 //
	}
}


