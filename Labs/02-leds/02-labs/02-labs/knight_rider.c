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
#define LED_1   PB5     // AVR pin where green LED is connected
#define LED_2   PC5
#define LED_3   PC4
#define LED_4   PC3
#define LED_5   PC2
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
    // Green LED at port B
    // Set pin as output in Data Direction Register...
    DDRB = DDRB | (1<<1);
    // ...and turn LED off in Data Register
    PORTB = PORTB & ~(1<<LED_2);

    // Configure the second LED at port C
    DDRC = DDRC | (1<<LED_1);
    PORTC = PORTC & ~(1<<LED_2);

    // Configure Push button at port D and enable internal pull-up resistor
	DDRD = DDRD & ~ (1<<BUTTON);
	PORTD = PORTD & ~ (1<<BUTTON);

    // Infinite loop
    while (1)
    {
        if (((PIND >> BUTTON) & 1) == 1)
		{
        _delay_ms(BLINK_DELAY);
        PORTB = PORTB ^ (1<<LED_1);
        PORTC = PORTC ^ (1<<LED_2);
        _delay_ms(BLINK_DELAY);
        PORTB = PORTB ^ (1<<LED_1);
        PORTC = PORTC ^ (1<<LED_2);
		}
    }

    // Will never reach this
    return 0;
}