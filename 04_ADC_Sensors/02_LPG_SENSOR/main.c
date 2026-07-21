
#include<pic.h>

#define RS RB3
#define RW RB4
#define EN RB5
#define LP RD6

void delay_ms(unsigned int ms)
{
	unsigned int i, j;
	for(i = 0; i < ms; i++)
	for(j = 0; j < 210; j++);
}

void lcd_init();
void cmd(unsigned char a);
void dat(unsigned char b);
void st(unsigned char *s);
void lcd_centre(unsigned char R, const char *s);

void lcd_init()
{
	delay_ms(20);
	cmd(0x38);
	cmd(0x0c);
	cmd(0x06);
	cmd(0x01);
	delay_ms(2);
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

void st(unsigned char *s)
{
	while(*s != '\0')
	{
	dat(*s++);
	}
}

void lcd_centre(unsigned char R, const char *s)
{	
	static unsigned char last = 0;

	unsigned char len = 0;
	while(s[len] != '\0')
	{
	len++;
	}
	
	unsigned char lp = (16 - last) / 2;
	
	if(last > 0)
	{
		if(R == 1)
		{
		cmd(0x80 + lp);
		}
		else
		{
		cmd(0x80 + lp);
		}
		for(unsigned i = 0; i < last; i++)
		{
			dat(' ');
		}
	}

	unsigned char cp = (16 - len) / 2;
	if(R == 1) { cmd(0x80 + cp);}
	else { cmd(0xc0 + cp);  }

	st((unsigned char *)s);

	last = len;

}


void main()
{
	TRISB = 0X00;
	TRISC = 0X00;
	TRISD6 = 1;
	
	lcd_init();
	while(1)
	{
	
	if(LP)
	{
	lcd_centre(1, "Detected");
	}
	else
	{
	lcd_centre(1, "ND");
	}
	}
}
