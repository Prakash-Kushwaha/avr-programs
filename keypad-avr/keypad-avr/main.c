/*
 * keypad-avr.c
 *
 * Created: 28-10-2024 13:12:45
 * Author : Prakash Kushwaha
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	// Configure rows of keypad as outputs and columns as inputs
	DDRA = 0x0F; // PA0-PA3 as output (rows), PA4-PA6 as input (columns)
	PORTA = 0xF0; // Enable pull-up resistors for PA4-PA6
	
	// Configure PORTD for 7-segment display
	DDRD = 0xFF; // All pins on PORTD as output
	PORTD = 0xFF; // Initially off (all high for common anode)
	
	// Array to store 7-segment patterns for digits 0-9 and additional symbols
	uint8_t array[12] = {0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88,0xC0, 0x89}; // For 0-9, A, b

	// Variable to store keypad value
	uint8_t key_value;

	while (1)
	{
		key_value = 0xFF; // Default to invalid key

		// Scan each row by setting it low and checking columns
		for (uint8_t row = 0; row < 4; row++)
		{
			PORTA = ~(1 << row); // Set current row low, others high

			_delay_ms(20); // Debounce delay

			// Check each column for a key press
			if (!(PINA & (1 << 4))) { key_value = row * 3 + 1; break; } // Column 1
			if (!(PINA & (1 << 5))) { key_value = row * 3 + 2; break; } // Column 2
			if (!(PINA & (1 << 6))) { key_value = row * 3 + 3; break; } // Column 3
		}

		// Reset rows after scanning
		PORTA = 0xF0;

		// Display the detected key value on 7-segment display
		if (key_value != 0xFF) // Valid key press
		{
			if (key_value <= 12) // Ensure it’s within range
			{
				PORTD = array[key_value - 1]; // Output pattern for the pressed key
			}
			else
			{
				PORTD = 0xFF; // If invalid key, turn display off
			}
		}
		else
		{
			PORTD = 0xFF; // If no key pressed, turn display off
		}
	}
	return 0;
}
