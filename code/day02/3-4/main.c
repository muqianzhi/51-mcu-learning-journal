#include <STC89C5xRC.H>
#include <INTRINS.H>

void Delay1ms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms){
		xms--;
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

unsigned char LEDNum;

void main()
{
	P2=~0x01;
	
	while(1){
		{
			if(P30==0){
				Delay1ms(20);
				while(P30==0);
				Delay1ms(20);
				LEDNum++;
				if(LEDNum>=8){
					LEDNum=0;
				}
				P2=~(0x01<<LEDNum);
			}
			if(P31==0){
				Delay1ms(20);
				while(P31==0);
				Delay1ms(20);
				if(LEDNum==0){
					LEDNum=7;
				}
				else{
					LEDNum--;
				}
				P2=~(0x01<<LEDNum);
			}
		}
	}
}