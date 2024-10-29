/*
 * 7seg-inteface.c
 *
 * Created: 17-10-2024 20:27:53
 * Author : Prakash Kushwaha
 */ 

#include <avr/io.h>
#define F_CPU 16000000L
#include <util/delay.h>

int main(void)
{
    /* Corrected array declaration */
    uint8_t array[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
    
    /* Setting PORTB and PORTD as output */
    DDRB = 0xFF;  // Setting PORTB as output
    DDRD = 0xFF;  // Setting PORTD as output

    while (1) 
    {
        for (int i = 0; i <= 9; i++)
        {
            PORTB = i;           // Display digit on PORTB if needed
            PORTD = array[i];    // Send segment data to PORTD
            _delay_ms(1000);
        }
    }
}
