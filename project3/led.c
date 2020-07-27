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
  led_update();
}
/*
void state_machine(char state){
  //each state makes a sound, except state one that silences it
  if(state == 1){
    buzzer_set_period(0);
  }

  else if(state == 2){
    //clearScreen(COLOR_BLUE);
    int notes[] = {2000, 1500, 1000, 500, 0};
    for(int i= 0; i<5; i++){
      buzzer_set_period(notes[i]);
      __delay_cycles(2500000);
    }
    
    //buzzer_set_period(1500);
    
  }

  else if(state == 3){
    //clearScreen(COLOR_RED);
    int notes[] = {500, 1000, 1500, 2000, 0};
    for(int i=0; i<5; i++){
      buzzer_set_period(notes[i]);
      __delay_cycles(2500000);
    }
  }

  else if(state == 4){
    //clearScreen(COLOR_GRAY);
    int notes[] = {1000, 2000, 500, 1500, 0};
    for(int i=0; i<5; i++){
      buzzer_set_period(notes[i]);
      __delay_cycles(2500000);
    }
    //buzzer_set_period(2500);
  }

  //else
  //buzzer_set_period(0);

}
*/

/*
void screenDis(char state){
  if(state == 1){
    clearScreen(COLOR_WHITE);
  }

  else if(state == 2){
    clearScreen(COLOR_BLUE);
  }

  else if(state == 3){
    clearScreen(COLOR_GREEN);
  }

  else if(state == 4){
    clearScreen(COLOR_YELLOW);
  }
  
}
*/


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
