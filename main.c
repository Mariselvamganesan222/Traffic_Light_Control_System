#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5;  
    P2DIR |= BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5;  
    P1OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5); 
    P2OUT |= BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5; 

    while (1) {
        P1OUT |= BIT0;   
        P1OUT &= ~(BIT1 | BIT2 | BIT3 | BIT4); 
        P1OUT |= BIT5; 
        P2OUT |= BIT0 | BIT1 | BIT3 |  BIT4 ; 
        P2OUT &= ~(BIT2 | BIT5);
        __delay_cycles(200000);
 
        P1OUT &= ~BIT0; 
        P1OUT |= BIT1;   
        __delay_cycles(30000);
        P1OUT &= ~BIT1;  
        P1OUT |= BIT2;  

    
        P1OUT |= BIT3; 
        P1OUT &= ~(BIT0 | BIT1 | BIT4 | BIT5); 
        P2OUT |= BIT0 | BIT1 | BIT3 | BIT4 ; 
        P2OUT &= ~(BIT2 | BIT5);
        __delay_cycles(250000);
        P1OUT &= ~BIT3; 
        P1OUT |= BIT4;  
        __delay_cycles(30000);
        P1OUT &= ~BIT4;  
        P1OUT |= BIT5;   

       
        P2OUT &= ~BIT0;  
        P1OUT &= ~(BIT0 | BIT1 | BIT3 | BIT4); 
        P1OUT |=(BIT2 | BIT5);
        P2OUT |= BIT1 | BIT2 | BIT3 | BIT4 ;   
        P2OUT &= ~BIT5;
        __delay_cycles(1500000);

        P2OUT |= BIT0;   
        P2OUT &= ~BIT1;  
        __delay_cycles(30000);
        P2OUT |= BIT1;   
        P2OUT &= ~BIT2;  

      
        P2OUT &= ~BIT3;  
        P1OUT &= ~(BIT0 | BIT1 | BIT3 | BIT4 );
        P1OUT |=(BIT2 | BIT5);
        P2OUT |= BIT0 | BIT1 | BIT4 | BIT5;  
        P2OUT &= ~BIT2;
        __delay_cycles(100000);

        P2OUT |= BIT3;  
        P2OUT &= ~BIT4;  
        __delay_cycles(30000);
        P2OUT |= BIT4;   
        P2OUT &= ~BIT5; }
}

