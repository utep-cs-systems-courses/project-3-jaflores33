#include <msp430.h>

#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void state_machine(int state){

  int notes[6]={0, 500, 1000, 1500, 2000, 0};
  
  switch(state){

  case 1:
    for(int i=3; i>=0; i--){
      buzzer_set_period(notes[i]);
      __delay_cycles(2500000);
    }
    clearScreen(COLOR_WHITE);
    break;
    
  case 2:
    //notes[] = {1000, 2000, 500, 1500, 0};

    for(int i=0; i<6; i++){
      buzzer_set_period(notes[i]);
      __delay_cycles(2500000);
    }
    clearScreen(COLOR_BLUE);
    break;

  case 3:
    //notes[] = {1000, 2000, 500, 1500, 0};

    for(int i=5; i>=0; i--){
      buzzer_set_period(notes[i]);
      __delay_cycles(2500000);
    }
    clearScreen(COLOR_RED);
    break;
    
  case 4:
    //notes[] = {1000, 2000, 500, 1500, 0};

    for(int i=2; i<6; i++){
      buzzer_set_period(notes[i]);
      __delay_cycles(2500000);
    }
    clearScreen(COLOR_YELLOW);
    break;

  default:
    buzzer_set_period(0);
    break;
  }
  
}
