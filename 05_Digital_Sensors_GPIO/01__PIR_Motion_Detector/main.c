#include<pic.h>

#define PIR RD0

#define RS   RB0
#define RW RB1
#define EN  RB2


void delay_ms(unsigned int ms)
{
	unsigned int i,j;
	for(i = 0; i < ms; i++)
	for(j = 0; j < 200; j++);
}

void cmd(unsigned char a)
{
	PORTC = a;
	RS = 0;
	RW = 0;
	EN = 1;
	delay_ms(2);
	EN = 0;
      delay_ms(2);
}

void dat(unsigned char b)
{
	 PORTC = b;
	 RS = 1;
	 RW = 0;
	 EN = 1;
	 delay_ms(2);
	 EN = 0;
        delay_ms(2);
}

void Str(const unsigned char *s)
{
	while(*s != '\0')
	{
	dat(*s);
	*s++;
	}
}

void lcd_init()
{
	cmd(0x38);
	cmd(0x0c);
	cmd(0x06);
	cmd(0x80);
}


void main()
{
	TRISC = 0X00;
	TRISB0 = 0X00;
	TRISB1 = 0X00;
	TRISB2 = 0X00;
	TRISD = 0X0F;
	lcd_init();
	
	unsigned char S = 2;
	while(1)
	{ 
	
	if(PIR != S)
	{
	cmd(0x80);
	if(PIR == 1)
	{
	cmd(0x80);
	Str(" OBJ DETECTED  ");
	delay_ms(2);
	}
	
	else
	{
	cmd(0x80);
	Str("NO OBJ DETECTED ");
	}
	S = PIR;
	}
	}
}

