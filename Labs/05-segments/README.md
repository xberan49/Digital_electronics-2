# Lab 5: TEREZA BERÁNKOVÁ
Link to your `Digital-electronics-2` GitHub repository:

   [https://github.com/xberan49/Digital_electronics-2](https://github.com/xberan49/Digital_electronics-2)


### 7-segment library
0. In the following table, write the binary values of the segments for display 0 to 9 on a common anode 7-segment display.

   | **Digit** | **A** | **B** | **C** | **D** | **E** | **F** | **G** | **DP** |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
   | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
   | 1 | 1 | 0 | 0 | 1 | 1 | 1 | 1 | 1 |
   | 2 | 0 | 0 | 1 | 0 | 0 | 1 | 0 | 1 |
   | 3 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 |
   | 4 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 1 |
   | 5 | 0 | 1 | 0 | 0 | 1 | 0 | 0 | 1 |
   | 6 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
   | 7 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 |
   | 8 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
   | 9 | 0 | 0 | 0 | 1 | 1 | 0 | 0 | 1 |
   
1. In your words, describe the difference between Common Cathode and Common Anode 7-segment display.
   * CC SSD - all cathodes are connected together to logic 0 or ground
            - the individual segments are illuminated by application of a HIGH or logic 1
   * CA SSD - all anodes are connected together to logic 1 
            - the individual segments are illuminated by applying a ground logic 0 or LOW

2. Code listing with syntax highlighting of two interrupt service routines (`TIMER0_OVF_vect`, `TIMER0_OVF_vect`) from counter application with at least two digits, ie. values from 00 to 59:

```c
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment counter value from 00 to 59.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
   cnt0++;
    if (cnt0 > 9)
    { cnt0=0;
    }
	
    cnt1++;
    if (cnt1 > 5)
    { cnt1=0;
    }   

}
```

```c
/**********************************************************************
 * Function: Timer/Counter0 overflow interrupt
 * Purpose:  Display tens and units of a counter at SSD.
 **********************************************************************/
ISR(TIMER0_OVF_vect)
{
    static uint8_t pos = 0;

    if (pos == 0)
	{
	    SEG_update_shift_regs(cnt0,pos);
        }
    else
	{
	    SEG_update_shift_regs(cnt1,pos);
        }
	
    pos++;
    if (pos > 1) 
	{
	    pos = 0;
	}

}
```

3. Flowchart figure for function `SEG_clk_2us()` which generates one clock period on `SEG_CLK` pin with a duration of 2&nbsp;us. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/05-segments/diagram.png](https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/05-segments/diagram.png)


### Kitchen alarm

Consider a kitchen alarm with a 7-segment display, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

1. Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/05-segments/scheme.png](https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/05-segments/scheme.png)
