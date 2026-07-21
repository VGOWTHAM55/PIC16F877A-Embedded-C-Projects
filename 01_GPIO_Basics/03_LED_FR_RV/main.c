#include<pic.h>

void delay()
{
	unsigned int i;
	for(i = 0; i < 50000; i++);

}

void main()
{
	TRISB = 0X00;
	PORTB = 0x00;
	unsigned char i;

	while(1)
	{
				
		for(i = 0x01; i < 0x80; i <<= 1)
		{
			PORTB = i;
			delay();
		}
		
		for(i = 0x80; i >= 0x01; i >>= 1)
		{
    		PORTB = i;
    		delay();
		}
	}
}
		
