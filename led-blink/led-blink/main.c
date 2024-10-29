/*
 * led-blink.c
 *
 * Created: 02-10-2024 17:53:24
 * Author : Prakash Kushwaha
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		DDRA |= 0x1 << 6;
		PORTA |= 0x1 << 6;
		_delay_ms(1000);
		PORTA &= ~(0x1 << 6);
		_delay_ms(1000);
    }
}

