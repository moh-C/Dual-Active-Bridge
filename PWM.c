#include <io.h>
#include <delay.h>

void setupTimer()
{
    TCCR1B = 0x18; 
    TCCR1A = 0x50;
    ICR1H = 0x27;
    ICR1L = 0x0F;    
    TCNT1=0x0;
    TCCR1B |= 2;
}


void main(void)
{
    int cnt = 0;
    DDRB = 0xFF;
    DDRD = 0xFF;
    setupTimer();
    OCR1A = 0;
    while (1)
    {
        for(cnt=1;cnt<100;cnt++)
        {
            OCR1B = (int) (100 * cnt - 1);
            delay_ms(100);
        }                
    }
}   