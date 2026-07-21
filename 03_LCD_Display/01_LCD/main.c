#include<pic.h>

#define RS RB0
#define RW RB1
#define EN RB2


void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 110; j++);
}

void cmd(unsigned char a)
{
	PORTC  = a;
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

void str(unsigned char *s)
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
	cmd(0x0C);   
	cmd(0x06);    
	cmd(0x01);
	delay_ms(5);
}

void main()
{	
	TRISB0 = 0;
	TRISB1 = 0;
	TRISB2 = 0;
	TRISC = 0X00;
	
	lcd_init();
	cmd(0x84);
	str("GOWTHAM");
	while(1)
	{
	cmd(0x08);
	delay_ms(500);
	cmd(0x0c);
	delay_ms(500);
	}
}
	

