/*
 * main_dynamic_indicators.cpp
 *
 * Created: 31.01.2025 13:11:52
 * Author : 416-22
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 8000000


int R1, R2, num = 0;
int n=0;

void init_port();
void ini_tm2();
void segment_seven (int i);
void ledprint(int num);
int segchar();

ISR(TIMER2_COMP_vect)
{
		if (n==0)
		{
			PORTB|=(1<<PB0);
			PORTB&=~(1<<PB1);
		}
		else
		{
			PORTB|=(1<<PB1);
			PORTB&=~(1<<PB0);
		}
		
		n++;
		if (n>1) n=0;
}


int main(void)
{
	init_port();
	ini_tm2();
	
    /* Replace with your application code */
    while (1) 
    {
		ledprint(num);
    }
}

void init_port()
{
	DDRD = 0xFF;
	PORTD = 0x00;
	DDRB = 0b00001111;
	PORTB = 0b00100000;	
}

void ini_tm2()
{
	//включить Т2 в режиме СТС
	TCCR2=(1<<CS22)|(1<<CS21)|(1<<WGM21)//поделить частоту на 256
	//включить прерывание по совпадению
	OCR2=100;//записать в регистр OCR2 число 100
	sei();//разрешить все прерывания

}

void segment_seven (int i)
{
	
}

void ledprint(int num)
{
	R1 = num/10;
	R2 = num%10;
}
