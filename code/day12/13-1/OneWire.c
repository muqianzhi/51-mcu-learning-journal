#include <STC89C5xRC.H>

sbit OneWire_DQ=P3^7;

unsigned char OneWire_Init()
{
	unsigned char i;
	unsigned char AckBit;
	OneWire_DQ=1;
	OneWire_DQ=0;
	i = 227;while (--i);
	OneWire_DQ=1;
	i = 29;while (--i);
	AckBit=OneWire_DQ;
	i = 227;while (--i);
	return OneWire_DQ;
}

void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ=0;
	i = 3;while (--i);
	OneWire_DQ=Bit;
	i = 22;while (--i);
	OneWire_DQ=1;
}

unsigned char OneWire_ReciveBit()
{
	unsigned char i;
	unsigned char Bit;
	OneWire_DQ=0;
	i = 2;while (--i);
	OneWire_DQ=1;
	i = 2;while (--i);
	Bit=OneWire_DQ;
	i = 20;while (--i);
	return Bit;
}

void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++){
		OneWire_SendBit(Byte&(0x01<<i));
	}
}

unsigned char OneWire_ReciveByte()
{
	unsigned char i;
	unsigned char Byte=0x00;
	for(i=0;i<8;i++){
		if(OneWire_ReciveBit()){Byte|=(0x01<<i);}
	}
	return Byte;
}