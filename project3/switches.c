#include <msp430.h>
#include "switches.h"
#include "led.h"

#include <lcdutils.h>
#include <lcddraw.h>

#include "stateMachine.h"
#include "sm.h"

#include <libTimer.h>

char switch_state_down, switch_state_changed; /* effectively boolean */

char redraw;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;

  /* update switch interrupt to detect changes from current buttons */

  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */

  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */

  return p2val;

}

void switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */

  P2IE |= SWITCHES;/* enable interrupts from switches */

  P2OUT |= SWITCHES;/* pull-ups for switches */

  P2DIR &= ~SWITCHES;/* set switches' bits for input */

  switch_update_interrupt_sense();
  switch_interrupt_handler();

  
  //led_update();
  //ledLight(0);
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  switch_state_changed=1;

  if(p2val & SW1 ? 0 : 1){
    //    switch_state_down=1;
    //state_machine(1);
    moveState(1);
    redraw=1;
    
  }

  else if(p2val & SW2 ? 0 : 2){
    //switch_state_down=1;
    //state_machine(2);
    moveState(2);
    redraw=1;
    
  }

  else if(p2val & SW3 ? 0 : 3){
    //switch_state_down=1;
    //state_machine(3);
    moveState(3);
    redraw=1;
  }

  else if(p2val & SW4 ? 0 : 4){
    //switch_state_down=1;
    //state_machine(4);
    moveState(4);
    redraw=1;
  }

  //else{
    //state_machine(0);
    //switch_state_down=0;
    //}
  //switch_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */

  //led_update();
  
}
