
#include<pic.h>

#define RS RB0
#define RW RB1
#define EN RB2

void delay_ms(unsigned int ms)
{
	unsigned int i, j;
	for(i = 0; i < ms; i++)
	for(j = 0; j < 1200; j++);
}

void lcd_init();
void cmd(unsigned char a);
void dat(unsigned char b);
void str(unsigned char *s);


void lcd_init()
{
	cmd(0x38);
	cmd(0x0c);
	cmd(0x06);
	cmd(0x01);
}

void cmd(unsigned char a)
{
	PORTC = a;
	RS = 0;
	RW = 0;
	EN = 1;
	delay_ms(2);
	EN = 0;
}

void dat(unsigned char b)
{
	PORTC = b;
	RS = 1;
	RW = 0;
	EN = 1;
	delay_ms(2);
	EN = 0;
}

void str(unsigned char *s)
{
	while(*s != '\0')
	{
	dat(*s++);
	}
}


void adc()
{
	unsigned int Value;
	ADCON1 = 0X80;
	ADCON0 = 0X41;
	delay_ms(2);
	GODONE = 1;

	while(GODONE);
	Value = ((ADRESH << 8) | ADRESL);
	Value = (Value / 3) - 1;
	dat((Value / 1000) + 48);
	dat(((Value / 100) % 10) + 48);
	dat(((Value / 10) % 10) + 48);
	dat((Value % 10) + 48);
}

void main()
{
	TRISB0 = 0;
	TRISB1 = 0;
	TRISB2 = 0;
	TRISC = 0X00;
	TRISA0 = 1;
	lcd_init();
	str("ADC Value : ");
	while(1)
	{
	cmd(0x8c);
	adc();
	delay_ms(300);
	}
}
 	
	

