/*
 * Created: 16-08-2024 18:34:06
 * Author : Prakash Kushwaha
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>      // Header file for AVR I/O port definitions
#include <util/delay.h>  // Header file for delay functions

// PB5 corresponds to digital pin 13 on Arduino Nano
#define LED_PIN PB5

int main(void)
{

	// Set the bit corresponding to LED_PIN (PB5) to 1 to configure it as an output
	DDRB |= (1 << LED_PIN);

	// Infinite loop to repeatedly blink the LED
	while (1)
	{

		// Set the bit corresponding to LED_PIN (PB5) to 1 to turn the LED on
		PORTB |= (1 << LED_PIN);

		// Wait for 1 second (1000 milliseconds)
		_delay_ms(1000);


		// Clear the bit corresponding to LED_PIN (PB5) to 0 to turn the LED off
		PORTB &= ~(1 << LED_PIN);

		// Wait for another 1 second (1000 milliseconds)
		_delay_ms(1000);
	}
	return 0;
}
