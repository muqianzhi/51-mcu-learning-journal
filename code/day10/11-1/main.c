#include <STC89C5xRC.H>
#include "Buzzer.h"
#include "Key.h"
#include "Nixie.h"

sbit Buzzer=P2^5;

unsigned char KeyNum;

void main()
{
	Nixie(1,0);
	while(1){
		KeyNum=Key();
		if(KeyNum)
		{
			Buzzer_Time(100);
			Nixie(1,KeyNum);
		}
	}
}