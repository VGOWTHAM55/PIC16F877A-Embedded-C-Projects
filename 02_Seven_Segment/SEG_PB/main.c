#include<pic.h>

#define PB RC0


unsigned char c[] = {0X00, 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

unsigned char Count = 0;

void delay_ms(unsigned int ms)
{
	unsigned int i, j;
	for(i = 0; i < ms ; i++)
	for(j = 0; j < 210; j++);
}
	
void main()
{
TRISD = 0X00;
TRISC0 = 1;
	PB = 1;

Count = 0;
PORTD = c[Count];
while(1)
	{
	if(PB == 0)
		{
		delay_ms(20);
		if(PB == 0)
		{
			Count++;
			if(Count >= 17)
			{
			Count = 1;
			}
	
			PORTD = c[Count];
			while(PB == 0);
		}
		}
	}
}
