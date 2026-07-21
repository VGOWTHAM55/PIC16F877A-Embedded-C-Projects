
#include <pic.h>

__CONFIG(0x3F3A);

#define RS   RB3
#define RW  RB4
#define EN  RB5
#define IR   RD7

void delay_ms(unsigned int ms)
{
    unsigned int i,j;

    for(i=0;i<ms;i++)
        for(j=0;j<210;j++);
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

void dat(unsigned char a)
{
    PORTC = a;

    RS = 1;
    RW = 0;

    EN = 1;
    delay_ms(2);
    EN = 0;
}

void str(const char *s)
{
    while(*s)
        dat(*s++);
}

void lcd_init()
{
    delay_ms(50);

    cmd(0x38);
    cmd(0x0C);
    cmd(0x06);
    cmd(0x01);

    delay_ms(10);
}

void main()
{
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD7 = 1;
    lcd_init();
    while(1)
    {
        if(IR == 0)
        {
            cmd(0x80); 
            str("    Detected    "); 
            
            delay_ms(200);
        }
        else
        {    
            cmd(0x80);
            str("       ND       "); 
            
            delay_ms(200);
        }
    }	
}
