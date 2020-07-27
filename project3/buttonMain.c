#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

#include "stateMachine.h"

#include <lcdutils.h>
#include <lcddraw.h>

//#define GREEN_LED BIT6

void main(void)
{
  configureClocks();
  switch_init();
  //led_init();
  buzzer_init();

  lcd_init();

  
or_sr(0x18);  // CPU off, GIE on
} 
