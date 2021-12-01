/*
 * servo.c
 *
 * Created: 01.12.2021 13:35:04
 * Author : tereza.berankova
 */ 

/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000  // CPU frequency in Hz required for UART_BAUD_SELECT
# define servo PB1
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include "gpio.h"
#include <stdlib.h>         // C library. Needed for conversion function
#include <stdio.h>         // C library. Needed for conversion function
#include <util/delay.h>     // Functions for busy-wait delay loops

int main(void)
{
	GPIO_config_output(&DDRB, servo);
	GPIO_write_high(&PORTB, servo);
	_delay_ms(2);
	GPIO_write_low(&PORTB, servo);
	_delay_ms(18);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

