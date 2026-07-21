#include<pic.h>

void delay_ms(unsigned int ms)      
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 210; j++);
}

void main()
{
	unsigned char s[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
	
	unsigned char i;
	
	TRISD = 0X00;
	while(1)
	{
		for(i = 0; i <=15; i++)
		{
			PORTD = s[i];
			delay_ms(1000);
		}
	}
}
