#include<pic.h>

#define D1 RD0
#define D2 RD1
#define D3 RD2
#define D4 RD3

void delay()
{
    unsigned int i;
    for(i = 0; i < 200; i++);    
}


unsigned char S[] ={0X00, 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
unsigned int n = 0;
unsigned int count = 0;
unsigned char  d1, d2, d3, d4;

void main()
{

	TRISC = 0X00;
	TRISD = 0X00;

while(1)
{
	for(count = 0; count < 200; count++)
    {
	d1 = n / 1000;
	d2 = (n / 100) % 10;
	d3 = (n / 10) % 10;
	d4 = n % 10;

	PORTC = S[d1];
	D1 = 0; D2 = 1; D3 = 1; D4 = 1;
	delay();
	D1 = 1;

	PORTC = S[d2];
	D1 = 1; D2 = 0; D3 = 1; D4 = 1;
	delay();
	D2 = 1;

	PORTC = S[d3];
	D1 = 1; D2 = 1; D3 = 0; D4 = 1;
	delay();
	D3 = 1;

	PORTC = S[d4];
	D1 = 1; D2 = 1; D3 = 1; D4 = 0;
	delay();
	D4 = 1;
	}
	n++;
	if(n > 9999) n = 0;
	}
}
