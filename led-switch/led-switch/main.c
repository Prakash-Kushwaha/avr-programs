/*
 * led-switch.c
 *
 * Created: 03-10-2024 20:26:10
 * Author : Prakash Kushwaha
 */ 

#include <avr/io.h>
#define F_CPU 16000000L // Defining CPU frequency i.e. 16MHz
#include <util/delay.h>

#define SWITCH_PIN 4 // Define switch pin (PD4)
#define LED_PIN 5    // Define LED pin (PD5)

int main(void)
{
    // Set PD4 as input for switch and PD5 as output for LED
    DDRD &= ~(1 << SWITCH_PIN); // Clear bit for input (PD4)
    DDRD |= (1 << LED_PIN);     // Set bit for output (PD5)
    
    while (1) 
    {
        // Read the switch status
        //uint8_t switch_status = PIND & (1 << SWITCH_PIN);
        uint8_t switch_status = PIND & (1 << PIND4);
        
        if (switch_status) {  
            PORTD |= (1 << LED_PIN); // Turn on LED if switch is pressed
        } else {
            PORTD &= ~(1 << LED_PIN); // Turn off LED if switch is not pressed
        }
        
        _delay_ms(10); // De-bounce delay
    }
}
