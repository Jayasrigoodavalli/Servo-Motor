/*
 * GccApplication2.c
 *
 * Created: 16-May-19 2:57:21 PM
 * Author : JAYASREE
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	//Configure Timer1
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);//Non inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALAR=64 mode 14(FAST PWM)
	ICR1=4999; //FPWM=50hz(Period =50ms standard)
	DDRD|=(1<<PD5); //PWM Pins as o/p
    /* Replace with your application code */
    while (1) 
    {
		OCR1A=97;//0 degree
		_delay_ms(500);
		OCR1A=280;//90 degree
		_delay_ms(500);
		OCR1A=535;//180 degree
		_delay_ms(500);
		
    }
}

