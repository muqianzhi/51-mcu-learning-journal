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

void main()
{
	while(1){
		{
			if(P31==0){
				Delay1ms(20);
				while(P31==0);
				Delay1ms(20);
				P20=~P20;
			}
		}
	}
}