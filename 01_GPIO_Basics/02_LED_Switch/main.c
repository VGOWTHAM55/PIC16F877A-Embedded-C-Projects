#include<pic.h>

#define SW RB0
void delay()
{
	unsigned int i;
	for(i =0; i < 30000; i++);
}
void main()
{
	ADCON1 = 0x06;
	TRISA = 0X00;
	TRISB = 0X0F;
	
	while(1)
	{	
		PORTA = 0X00;
		if(SW == 0)
		{
		PORTA = 0x01;
		delay();
		}
		else
		{
		PORTA = 0X00;
		delay();
		}
	}
}
	
