# Lab 1: YOUR_FIRSTNAME FAMILYNAME

Link to your `Digital-electronics-2` GitHub repository:

   [https://github.com/xberan49/Digital_electronics-2](https://github.com/xberan49/Digital_electronics-2)


### Blink example

1. What is the meaning of the following binary operators in C?
   * `|`
      - Bitwise OR
      - If a = 1001 and b=1111 then a|b gives 1111
   * `&`
      - Bitwise AND
      - If a = 1001 and b=1111 then a&b gives 1001
   * `^`
      - Bitwise XOR
      - If a = 1001 and b=1111 then a^b gives 0110
   * `~`
      - Bitwise Complement
      - If a=01011 then ~a gives 10100
   * `<<`
      - Bitwise Shift Left	
      - If a=1010 and b=1 then a<<b gives 0100 (Left shifted by 1 and one 0 is inserted at the end)
   * `>>`
      - Bitwise Shift Right	
      - If a=1111 and b=2 then a>>b gives 0011 (Right shifted by 2 and two 0’s are inserted at the beginning)
      
2. Complete truth table with operators: `|`, `&`, `^`, `~`

| **b** | **a** |**b or a** | **b and a** | **b xor a** | **not b** |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 |



### Morse code

1. Listing of C code with syntax highlighting which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED:

```c
int main(void)
{
    // Set pin as output in Data Direction Register
    // DDRB = DDRB or 0010 0000
    DDRB = DDRB | (1<<LED_GREEN);

    // Set pin LOW in Data Register (LED off)
    // PORTB = PORTB and 1101 1111
    PORTB = PORTB & ~(1<<LED_GREEN);

    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(SHORT_DELAY);

        // Invert LED in Data Register
        // PORTB = PORTB xor 0010 0000
        PORTB = PORTB ^ (1<<LED_GREEN);
				_delay_ms(200); //DOT
		PORTB = PORTB ^ (0<<LED_GREEN);
				_delay_ms(SHORT_DELAY);		
			
		PORTB = PORTB ^ (1<<LED_GREEN);
				_delay_ms(1500); //COMMA
		PORTB = PORTB ^ (0<<LED_GREEN);
				_delay_ms(SHORT_DELAY);	
    }

    // Will never reach this
    return 0;
}
```


2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![your figure]()
