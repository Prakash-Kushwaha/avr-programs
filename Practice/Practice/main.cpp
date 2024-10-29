/*
 * Practice.cpp
 *
 * Created: 18-08-2024 09:12:37
 * Author : Prakash Kushwaha
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define INBUILT_LED PB5

int main(void)
{
    /* Replace with your application code */
    DDRB |= 1 << INBUILT_LED;
	while (1) 
    {
		PORTB |= 1 << INBUILT_LED;
		_delay_ms(1000);
		PORTB &= 0 << INBUILT_LED;
		_delay_ms(1000);
    }
	return 0;
}

