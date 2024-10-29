/*
 * theory-programs.c
 *
 * Created: 05-10-2024 13:15:18
 * Author : Prakash Kushwaha
 */ 

#include <avr/io.h>
#define F_CPU 16000000L
#include <util/delay.h>

// Write an AVR C-program to send value 00 to FFH to PORTB.
 //int main(void)
//{
	//DDRB = 0xFF;
    //
	//for (int i=0x0; i <=0xFF; i++){
		//PORTB = i;
	//}
//}


// Write an AVR C-program to toggle all the PINS of PORTC continuously with a 10ms delay use a predefined delay function in AVR.
//int main(void){
	//while(1){
		//PORTC = ~(PORTC);
		//_delay_ms(10);
	//}
//}


// Write a program to toggle PINB4 continuously without disturbing other PINS.
int main(void){
	while(1){
		if (~PORTB){
			PORTB |= (1 << PINB4);	// Set the PORTB 4	
		}
		PORTB &=  ~(1 << PINB4);	// Clear the PORTB 4	
	}
}