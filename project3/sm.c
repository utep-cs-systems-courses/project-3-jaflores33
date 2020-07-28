#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "sm.h"

void moveState(int s){
  switch(s){
  case 1:
    state_machine(1);
    break;
  case 2:
    state_machine(2);
    break;
  case 3:
    state_machine(3);
    break;
  case 4:
    state_machine(4);
    break;
  default:
    break;
  }
  
}
