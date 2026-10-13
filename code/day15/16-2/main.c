#include <STC89C5xRC.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

sbit DA=P2^1;

unsigned char Counter,Compare,i;

void main()
{
	Timer0_Init();
	while(1){
		for(i=0;i<100;i++){
			Compare=i;
			Delay(10);
		}
		for(i=100;i>0;i--){
			Compare=i;
			Delay(10);
		}
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0xA4;
	TH0 = 0xFF;
	Counter++;
	Counter%=100;
	if(Counter<Compare){
		DA=1;
	}
	else{
		DA=0;
	}
}