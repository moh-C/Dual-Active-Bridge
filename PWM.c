#include <io.h>
#include <delay.h>

// Global Variables
int topValueToggle = 0;

void setupTimer(int freq)
{
    int ICR_Value = 8000000 / 2 / 8 / freq - 1;
    topValueToggle = ICR_Value + 1; 
    
    // Stop the counter
    TCCR1B = 0x18; 
    
    // in mode 12 CTC
    TCCR1A = 0x50;
    
    // Change frequency
    ICR1H = (int) ICR_Value / 256;
    ICR1L = (int) ICR_Value % 256;    
    
    // Reset the counter
    TCNT1=0x0;
    
    // Start the counter and prescaler
    TCCR1B |= 2;
    
    // No phase shift for the first one
    OCR1A = 0;
}

void setPhase(int phase)
{    
    int result = 0;
    
    // int first_ = topValueToggle / 2;
    // int second_ = topValueToggle / 2 - 1;
    
    // int result = (first_ * phase) / 180;
    // result = result + ((second_ * phase) / 180);

    topValueToggle = topValueToggle - 1;
    result = topValueToggle * phase / 180;       
    OCR1B = (int) result; 
}


void main(void)
{
    int cnt = 0;
    DDRD = 0xFF;
    setupTimer(5000);
    while (1)
    {
        for(cnt=0; cnt <= 180;)
        {
            setPhase(cnt);
            cnt = cnt + 10;
            delay_ms(500);
        }                
    }
}   