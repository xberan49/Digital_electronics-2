/***********************************************************************
 * 
 * GPIO library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include "gpio.h"

/* Function definitions ----------------------------------------------*/

void GPIO_config_output(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name | (1 << pin_num);// * = pointer 
}


void GPIO_config_input_nopull(volatile uint8_t *reg_name, uint8_t pin_num)
{
     *reg_name = *reg_name | (1<<pin_num);// * = pointer
}


/**********************************************************************
 * Function: GPIO_config_input_pullup()
 * Purpose:  Configure one input pin and enable pull-up.
 * Input:    reg_name - Address of Data Direction Register, such as &DDRB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/

void GPIO_config_input_pullup(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name & ~(1<<pin_num);  // Data Direction Register
    reg_name++;                     // Change pointer to Data Register
    *reg_name = *reg_name | (1<<pin_num);   // Data Register
}

void GPIO_write_low(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name & ~(1<<pin_num);
}

void GPIO_write_high(volatile uint8_t *reg_name, uint8_t pin_num)
{
     *reg_name = *reg_name & ~(1<<pin_num);
}

void GPIO_toggle(volatile uint8_t *&PORTB, uint8_t pin_num)
{
     *reg_name = *reg_name ^(1<<pin_num);
}

void GPIO_read(volatile uint8_t *&PINB, uint8_t pin_num)
{
    return(*reg_name & (1 << pin_num));
}
