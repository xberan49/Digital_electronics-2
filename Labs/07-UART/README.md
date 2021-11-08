# Lab 7: TEREZA BERÁNKOVÁ

Link to this file in your GitHub repository:

[https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/07-UART/README.md](https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/07-UART/README.md)


### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   |  |
   | Up     | 0.495&nbsp;V | 101 |  |
   | Down   |  1,203 | 246 |  |
   | Left   | 1,970 | 403 |  |
   | Select | 3,182 | 651 |  |
   | none   | 5 | 1023 |  |

2. Code listing of ACD interrupt service routine for sending data to the LCD/UART and identification of the pressed button. Always use syntax highlighting and meaningful comments:

```c
/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display value on LCD and send it to UART.
 **********************************************************************/
ISR(ADC_vect)
{
   uint16_t value = 0;
   char lcd_string[]= "0000";
   
   value = ADC;
   itoa(value, lcd_string, 10);//convert decimal value to string
   
   
   lcd_gotoxy(8,0);
   lcd_puts("  "); //clear
   lcd_gotoxy(8,0);
   lcd_puts(lcd_string);
   
   itoa(value, lcd_string, 16);//convert hexadecimal value to string
   
   lcd_gotoxy(13,0);
   lcd_puts("  ");
   lcd_gotoxy(13,0);
   lcd_puts(lcd_string);

}
```


### UART communication

1. (Hand-drawn) picture of UART signal when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd).

   ![your figure]()

2. Flowchart figure for function `uint8_t get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure]()


### Temperature meter

Consider an application for temperature measurement and display. Use temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, one LED and a push button. After pressing the button, the temperature is measured, its value is displayed on the LCD and data is sent to the UART. When the temperature is too high, the LED will start blinking.

1. Scheme of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![your figure]()
