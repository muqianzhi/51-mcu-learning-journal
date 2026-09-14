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
		P2=0xfe;
		Delay1ms(100);
		P2=0xfd;
		Delay1ms(100);
		P2=0xfb;
		Delay1ms(100);
		P2=0xf7;
		Delay1ms(100);
		P2=0xef;
		Delay1ms(100);
		P2=0xdf;
		Delay1ms(100);
		P2=0xbf;
		Delay1ms(100);
		P2=0x7f;
		Delay1ms(100);
	}
}