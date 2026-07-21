#include <pic.h>

#define D1 RD0
#define D2 RD1

unsigned char c[] =
{
    0x3F,0x06,0x5B,0x4F,0x66,
    0x6D,0x7D,0x07,0x7F,0x6F
};

unsigned int n = 0;
unsigned int count = 0;

void delay(unsigned int time)
{
    unsigned int i, j;

    for(i = 0; i < time; i++)
        for(j = 0; j < 100; j++);
}

void main()
{

	TRISC = 0X00;
	TRISD = 0X00;
    while(1)
    {
        
        PORTC = c[n/10];
        D1 = 0;
        D2 = 1;
        delay(5);
        D1 = 0;
	PORTC = 0x00;

        
       PORTC = c[n%10];
        D1 = 1;
        D2 = 0;
        delay(5);
        D2 = 0;
        PORTC = 0x00;

        count++;

        if(count > 300)
        {
            count = 0;
            n++;

            if(n > 99)
                n = 0;
        }
    }
}
