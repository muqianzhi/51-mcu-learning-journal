#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delay.h"

sbit Buzzer=P2^5;

void Buzzer_TimeDelay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;
		Buzzer_TimeDelay500us();
	}
}