/********************************************************/
/* iRobot Virtual Wall code for ATTiny13                */
/*                                                      */
/* Burn bootloader with internal oscillator of 9.6 MHz  */
/* Connect IR led to pin 5                              */
/********************************************************/

#define F_CPU 9600000UL  // Chip frequency

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  while (1) 
  {
    DDRB |= (1 << PB0);                 // Set PB0 IR LED to output (Pin 5)
    TCCR0A |= (1<<WGM01) | (1<<COM0A0); // CTC with toggle 
    TCCR0B |= (1<<CS00);                // Start timer with no prescaler
  
    OCR0A = 125;  // timer reaches 125 and toggles OC0A/PB0 pin (50% duty cycle)

    _delay_ms(1);

    TCCR0A = 0;
    TCCR0B = 0; // Stop the timer.
    PORTB = 0;  // All ports low.
    
    _delay_ms(1);
  }
}
