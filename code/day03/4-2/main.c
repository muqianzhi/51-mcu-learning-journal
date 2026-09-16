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

unsigned char NixieTable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void Nixie(unsigned int Location,Number)
{
	switch(Location){
		case 1:
			P24=1;P23=1;P22=1;
		break;
		case 2:
			P24=1;P23=1;P22=0;
		break;
		case 3:
			P24=1;P23=0;P22=1;
		break;
		case 4:
			P24=1;P23=0;P22=0;
		break;
		case 5:
			P24=0;P23=1;P22=1;
		break;
		case 6:
			P24=0;P23=1;P22=0;
		break;
		case 7:
			P24=0;P23=0;P22=1;
		break;
		case 8:
			P24=0;P23=0;P22=0;
		break;
	}
	P0=NixieTable[Number];
	Delay1ms(1);
	P0=0x00;
}

void main(){
	while(1){
		Nixie(1,1);
		Nixie(2,2);
		Nixie(3,3);
	}
}