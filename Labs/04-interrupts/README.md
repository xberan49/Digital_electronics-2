# Lab 4: TEREZA BERÁNKOVÁ

Link to your `Digital-electronics-2` GitHub repository:

   [https://github.com/xberan49/Digital_electronics-2](https://github.com/xberan49/Digital_electronics-2)


### Overflow times

1. Complete table with overflow times.

| **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Timer/Counter0 | 8  | 16u | 128u | -- | 1024u | -- | 4096u | 16384u | 
| Timer/Counter1 | 16 |   4096u  | 32768u | -- | 262144u | -- | 1048576u | 4194304u |
| Timer/Counter2 | 8  | 16u | 128u | 512u | 1024u | 2048u | 4096u | 16384u |


### Timer library

1. In your words, describe the difference between common C function and interrupt service routine.
   * Function - runs within the context of a main program
   * Interrupt service routine - runs within the context of the interrupt handler
  			       - running program is paused and when ISR is done program continues where it stopped

2. Part of the header file listing with syntax highlighting, which defines settings for Timer/Counter0:

```c
/**
 * @name  Definitions for 8-bit Timer/Counter0
 * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 8, F_CPU = 16 MHz
 */
// WRITE YOUR CODE HERE
/** @brief Stop timer, prescaler 000 --> STOP */
#define TIM0_stop()           TCCR0B &= ~((1<<CS02) | (1<<CS01) | (1<<CS00));
/** @brief Set overflow 16us, prescaler 001 --> 1 */
#define TIM0_overflow_16us()   TCCR0B &= ~((1<<CS02) | (1<<CS01)); TCCR0B |= (1<<CS00);
/** @brief Set overflow 128us, prescaler 010 --> 8 */
#define TIM0_overflow_128us()  TCCR0B &= ~((1<<CS02) | (1<<CS00)); TCCR0B |= (1<<CS01);
/** @brief Set overflow 1ms, prescaler 011 --> 64 */
#define TIM0_overflow_1ms() TCCR0B &= ~(1<<CS02); TCCR0B |= (1<<CS01) | (1<<CS00);
/** @brief Set overflow 4ms, prescaler 100 --> 256 */
#define TIM0_overflow_4ms()    TCCR0B &= ~((1<<CS01) | (1<<CS00)); TCCR0B |= (1<<CS02);
/** @brief Set overflow 16ms, prescaler // 101 --> 1024 */
#define TIM0_overflow_16ms()    TCCR0B &= ~(1<<CS01); TCCR0B |= (1<<CS02) | (1<<CS00);


/**
 * @brief Defines interrupt enable/disable modes for Timer/Counter0.
 */
/** @brief Enable overflow interrupt, 1 --> enable */
#define TIM0_overflow_interrupt_enable()  TIMSK0 |= (1<<TOIE0);
/** @brief Disable overflow interrupt, 0 --> disable */
#define TIM0_overflow_interrupt_disable() TIMSK0 &= ~(1<<TOIE0);


```

3. Flowchart figure for function `main()` and interrupt service routine `ISR(TIMER1_OVF_vect)` of application that ensures the flashing of one LED in the timer interruption. When the button is pressed, the blinking is faster, when the button is released, it is slower. Use only a timer overflow and not a delay library.

   ![https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/04-interrupts/lab%2004%20diagram.png](https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/04-interrupts/lab%2004%20diagram.png)
   
   
```c
int main(void)
{
	GPIO_config_input_pullup(&DDRD, BUTTON);
    // Configuration of LED(s) at port B
    GPIO_config_output(&DDRB, LED_D1);
    GPIO_write_low(&PORTB, LED_D1);

    // Configuration of 16-bit Timer/Counter1 for LED blinking
    // Set the overflow prescaler to 262 ms and enable interrupt
	TIM1_overflow_33ms()
    TIM1_overflow_4s();
    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
	  if(GPIO_read(&PIND, BUTTON) == 0)
	  {
		  TIM1_overflow_33ms();
	  }
	  else
	  {
		  TIM1_overflow_4s();
	  }
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Toggle D1 LED on Multi-function shield.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{

    GPIO_toggle(&PORTB,LED_D1);

}

```

### Knight Rider

1. Scheme of Knight Rider application with four LEDs and a push button, connected according to Multi-function shield. Connect AVR device, LEDs, resistors, push button, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/04-interrupts/shield_connection.PNG](https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/04-interrupts/shield_connection.PNG)
   
   ![https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/04-interrupts/knight_rider_scheme.PNG](https://github.com/xberan49/Digital_electronics-2/blob/main/Labs/04-interrupts/knight_rider_scheme.PNG)
