/*
 * LCD-test.c
 *
 * Created: 27-10-2024 15:16:08
 * Author : Prakash Kushwaha
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>

/* Global Variable Declarations */
unsigned char hours = 0;
unsigned char minutes = 0;
unsigned char seconds = 0;
char time[] = "00:00:00";

/* LCD function declarations */
void LCD_send_command(unsigned char cmnd);
void LCD_send_data(unsigned char data);
void LCD_init();
void LCD_goto(unsigned char y, unsigned char x);
void LCD_print(char *string);
void LCD_update_time(void);

/* Timer Counter 1 Compare Match A Interrupt Service Routine/Interrupt Handler */
ISR(TIMER1_COMPA_vect);

/* LCD Pin Configurations */
#define LCD_DATA_PORT PORTB
#define LCD_DATA_DDR  DDRB
#define LCD_DATA_PIN  PINB

#define LCD_CNTRL_PORT PORTC
#define LCD_CNTRL_DDR  DDRC
#define LCD_CNTRL_PIN  PINC

#define LCD_RS_PIN       5
#define LCD_RW_PIN       6
#define LCD_ENABLE_PIN   7
#define SET_HOUR         3
#define SET_MINUTE       4

int main(void)
{
	LCD_init();
	LCD_goto(1, 2);
	LCD_print("Digital-Clock");
	LCD_goto(2, 4);
	LCD_print(time);

	/* Configure buttons for setting hours and minutes */
	LCD_CNTRL_PORT |= (1 << SET_HOUR) | (1 << SET_MINUTE);

	/* Configure Timer1 */
	TCCR1B = (1 << CS12) | (1 << WGM12);
	OCR1A = 15625 - 1;
	TIMSK = 1 << OCIE1A;
	sei();

	while (1)
	{
		/* Check if the hour button is pressed */
		if (!(LCD_CNTRL_PIN & (1 << SET_HOUR)))
		{
			hours++;
			if (hours > 23)
			hours = 0;
		}

		/* Check if the minute button is pressed */
		if (!(LCD_CNTRL_PIN & (1 << SET_MINUTE)))
		{
			minutes++;
			if (minutes > 59)
			minutes = 0;
		}

		_delay_ms(250);
	}
}

/* Function to send a command 'cmnd' to the LCD module */
void LCD_send_command(unsigned char cmnd)
{
	LCD_DATA_PORT = cmnd;
	LCD_CNTRL_PORT &= ~(1 << LCD_RW_PIN);
	LCD_CNTRL_PORT &= ~(1 << LCD_RS_PIN);

	LCD_CNTRL_PORT |= (1 << LCD_ENABLE_PIN);
	_delay_us(2);
	LCD_CNTRL_PORT &= ~(1 << LCD_ENABLE_PIN);
	_delay_us(100);
}

/* Function to send the data 'data' to the LCD module */
void LCD_send_data(unsigned char data)
{
	LCD_DATA_PORT = data;
	LCD_CNTRL_PORT &= ~(1 << LCD_RW_PIN);
	LCD_CNTRL_PORT |= (1 << LCD_RS_PIN);

	LCD_CNTRL_PORT |= (1 << LCD_ENABLE_PIN);
	_delay_us(2);
	LCD_CNTRL_PORT &= ~(1 << LCD_ENABLE_PIN);
	_delay_us(100);
}

/* Initialize the LCD module */
void LCD_init()
{
	LCD_CNTRL_DDR = 0xFF;
	LCD_CNTRL_PORT = 0x00;
	LCD_DATA_DDR = 0xFF;
	LCD_DATA_PORT = 0x00;

	_delay_ms(10);
	LCD_send_command(0x38);  // 8-bit mode, 2-line display
	LCD_send_command(0x0C);  // Display on, cursor off
	LCD_send_command(0x01);  // Clear display
	_delay_ms(10);
	LCD_send_command(0x06);  // Increment cursor
}

/* Move the cursor to line y, column x on the LCD */
void LCD_goto(unsigned char y, unsigned char x)
{
	unsigned char firstAddress[] = {0x80, 0xC0, 0x94, 0xD4};
	LCD_send_command(firstAddress[y - 1] + x - 1);
	_delay_ms(10);
}

/* Print a string on the LCD */
void LCD_print(char *string)
{
	unsigned char i = 0;
	while (string[i] != 0)
	{
		LCD_send_data(string[i]);
		i++;
	}
}

/* Update the time displayed on the LCD */
void LCD_update_time()
{
	char temp[3];
	LCD_goto(2, 4);  // Reset cursor position on row 2, column 4

	itoa(hours / 10, temp, 10);
	LCD_print(temp);
	itoa(hours % 10, temp, 10);
	LCD_print(temp);
	LCD_print(":");

	itoa(minutes / 10, temp, 10);
	LCD_print(temp);
	itoa(minutes % 10, temp, 10);
	LCD_print(temp);
	LCD_print(":");

	itoa(seconds / 10, temp, 10);
	LCD_print(temp);
	itoa(seconds % 10, temp, 10);
	LCD_print(temp);
}

/* Timer Counter 1 Compare Match A Interrupt Service Routine/Interrupt Handler */
ISR(TIMER1_COMPA_vect)
{
	seconds++;
	if (seconds == 60)
	{
		seconds = 0;
		minutes++;
	}
	if (minutes == 60)
	{
		minutes = 0;
		hours++;
	}
	if (hours > 23)
	hours = 0;

	LCD_update_time();
}

