#include<pic.h>

#define IN1 RB0 
#define IN2 RB1
#define IN3 RB4
#define IN4 RB5 

#define RS RC0
#define RW RC1
#define EN RC2
#define SW RC4


void delay_us(unsigned int us)
{
    unsigned int i;
    for(i = 0; i < us; i++);   
}

void delay_ms(unsigned int ms)
{
    unsigned int i;
    for(i = 0; i < ms; i++)
        delay_us(110);         
}


void cmd(unsigned char a)
{
    PORTD = a;
    RS = 0;
    RW = 0;
    EN = 1;
    delay_ms(2);              
    EN = 0;
    delay_ms(2);              
}

void dat(unsigned char b)
{
    PORTD = b;
    RS = 1;
    RW = 0;
    EN = 1;
    delay_ms(1);
    EN = 0;
    delay_ms(1);
}

void str(unsigned char *s)
{
    while(*s != '\0')
    {
        dat(*s);
        s++;                  
    }
}

void lcd_init()
{
    delay_ms(20);             
    cmd(0x38);                 
    cmd(0x0C);                
    cmd(0x06);                 
    cmd(0x01);                 
    delay_ms(5);              
}


void main()
{
    TRISB0 = 0;
    TRISB1 = 0;
    TRISB4 = 0;
    TRISB5 = 0;
    TRISC0 = 0;
    TRISC1 = 0;
    TRISC2 = 0;
    TRISC4 = 1;               
    TRISD  = 0x00;

    lcd_init();

    unsigned char prev = 2;    

    while(1)
    {
        if(SW == 1)
        {
            if(prev != 1)      
            {
                IN1 = 1; IN2 = 0;   
                IN3 = 0; IN4 = 1;   

                cmd(0x01);         
                delay_ms(5);        
                cmd(0x80);         
                str("M1: FORWARD");
                cmd(0xC0);          
                str("M2: REVERSE");

                prev = 1;          
            }
        }
        else
        {
            if(prev != 0)      
            {
                
                IN1 = 0; IN2 = 0;
                IN3 = 0; IN4 = 0;

                cmd(0x01);         
                delay_ms(5);       
                cmd(0x80);         
                str("Press Button");
                cmd(0xC0);          
                str("Press Button");

                prev = 0;         
            }
        }
    }
}
