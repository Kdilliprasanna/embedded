#include <REGX51.H>

sbit LED_SW = P1^0;     
sbit LED_TM = P1^1;    

void SoftwareDelay()
{
    unsigned int i, j;

    for(i=0; i<200; i++)
        for(j=0; j<1275; j++);
}



void TimerDelay()
{
    TMOD = 0x01;      // Timer0 Mode1 (16-bit)

    TH0 = 0x3C;       
    TL0 = 0xB0;

    TR0 = 1;         

    while(TF0 == 0);  

    TR0 = 0;          
    TF0 = 0;          
}


void main()
{
    while(1)
    {
        LED_SW = ~LED_SW;      
        SoftwareDelay();

        LED_TM = ~LED_TM;      
        TimerDelay();
    }
}