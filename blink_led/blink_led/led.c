/*
 * Created : 17-08-2024 12:12:03
 * Author : Prakash Kushwaha
 */

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL  // Replace with your microcontroller's clock frequency


int main() {
	DDRB = 0xFF; // Setting Port B as Output
	
	while (1){
	// Setting the output of Port B to HIGH
	PORTB = 0xFF;
	_delay_ms(1000); // To generate a delay of 1s
	
	// Setting the output of Port B to LOW
	PORTB = 0x00;
	_delay_ms(1000);
	}
	return 0;
}