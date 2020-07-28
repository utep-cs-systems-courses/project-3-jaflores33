#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

#include "stateMachine.h"

#include <lcdutils.h>
#include <lcddraw.h>

//#define GREEN_LED BIT6

int redraw =1;

void main(void)
{

  P1DIR |= LED_GREEN;
  P1OUT |= LED_GREEN;

  
  configureClocks();
  switch_init();
  led_init();
  //dimLed();
  enableWDTInterrupts();
  
  buzzer_init();

  lcd_init();

  
  //or_sr(0x18);  // CPU off, GIE on

 for(;;){
   while(!redraw){
     P1OUT &= ~LED_GREEN;
     or_sr(0x18);
   }

   P1OUT |= LED_GREEN;
   __delay_cycles(2500000);
   redraw = 0;
 }
 
} 
