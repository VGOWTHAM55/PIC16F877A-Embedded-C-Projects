#include<pic.h>

void delay()
{
	unsigned int a = 0;
	for(a = 0; a < 30000; a++); 
}

void main()
{
	TRISB = 0;
	
	while(1)
	{
		PORTB = 0X0F;
		delay();
		PORTB = 0X00;
		delay();
	}
}
