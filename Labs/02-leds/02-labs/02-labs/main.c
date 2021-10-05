/***********************************************************************
 * 
 * Alternately toggle two LEDs when a push button is pressed.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_1   PC1  // AVR pin where green LED is connected
#define LED_2   PC2
#define LED_3   PC3
#define LED_4   PC4
#define LED_0   PC0
#define BUTTON      PD5
#define BLINK_DELAY 500
#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions

/* Functions ---------------------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle two LEDs when a push button is pressed.
 * Returns:  none
 **********************************************************************/
int main(void)
{
  
    // Configure the second LED at port C
    DDRC = DDRC | (1<<LED_1);
    PORTC0 = PORTC0 & ~(1<<LED_0);
	
    DDRC = DDRC | (1<<LED_1);
    PORTC1 = PORTC1 & ~(1<<LED_1);
	
	DDRC = DDRC | (1<<LED_2);
	PORTC2 = PORTC2 & ~(1<<LED_2);


	DDRC = DDRC | (1<<LED_3);
	PORTC3 = PORTC3 & ~(1<<LED_3);


	DDRC = DDRC | (1<<LED_4);
	PORTC4 = PORTC4 & ~(1<<LED_4);

    // Configure Push button at port D and enable internal pull-up resistor
	DDRD = DDRD & ~ (1<<BUTTON);
	PORTD = PORTD & ~ (1<<BUTTON);

    // Infinite loop
    while (1)
    {
        if (((PIND >> BUTTON) & 1) == 1)
		{
        _delay_ms(BLINK_DELAY);
        PORTC1 = PORTC1 ^ (1<<LED_1);
        _delay_ms(BLINK_DELAY);
		PORTC1 = PORTC1 ^ (1<<LED_1);
		PORTC0 = PORTC0 ^ (1<<LED_2);
		 _delay_ms(BLINK_DELAY)
        PORTC0 = PORTC0 ^ (1<<LED_2);
		PORTC3 = PORTC3 ^ (1<<LED_3);
		 _delay_ms(BLINK_DELAY)
		 PORTC3 = PORTC3 ^ (1<<LED_3);
		 PORTC4 = PORTC4 ^ (1<<LED_4);
		 _delay_ms(BLINK_DELAY)
		 PORTC4 = PORTC4 ^ (1<<LED_4);
		 PORTC5 = PORTC5 ^ (1<<LED_5);
		 _delay_ms(BLINK_DELAY)
		 PORTC5 = PORTC5 ^ (1<<LED_5);
		}
    }

    // Will never reach this
    return 0;
}