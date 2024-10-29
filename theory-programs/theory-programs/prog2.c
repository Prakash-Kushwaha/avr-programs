/*
 * prog2.c
 *
 * Created: 05-10-2024 13:19:45
 *  Author: Prakash Kushwaha
 */ 

#include <avr/io.h>
#define F_CPU 16000000L
#include <util/delay.h>

int main(){
	while (1){
		PORTC = ~(PORTC);
	}
}