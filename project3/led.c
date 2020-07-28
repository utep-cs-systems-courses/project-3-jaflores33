#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include <lcdutils.h>
#include <lcddraw.h>

void led_init()
{
  P1DIR |= LEDS;// bits attached to leds are output
  switch_state_changed = 1;
  //led_update();
}

void dimLed(){
  
  for(int i = 0; i<1000; i++){

    P1OUT = LED_RED;
    __delay_cycles(10000);
    P1OUT = LED_GREEN;
    __delay_cycles(10000);
    P1OUT = !LED_RED;
    __delay_cycles(10000);
    P1OUT = !LED_GREEN;
    __delay_cycles(10000);
  }
}

void led_update(){

  if (switch_state_changed) {

    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds

  }//END_______
  switch_state_changed = 0;

}
