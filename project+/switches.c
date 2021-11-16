#include <msp430.h>
#include "switches.h"
#include "led.h"

extern char redraw_screen;
const char down = 1;
const char up = 0;

char switch1_state, switch2_state,switch3_state,switch4_state, switch_state_changed;

static char switch_update_interrupt_sense(void)
{
  char p2val = P2IN;
  P2IES |= (p2val & P2_SWITCHES);
  P2IES &= (p2val | ~P2_SWITCHES);
  return p2val;
}
void switch_p2_init(void)
{
  P2REN |=  P2_SWITCHES;
  P2IE |= P2_SWITCHES;
  P2OUT |= P2_SWITCHES;
  P2DIR &= ~P2_SWITCHES;
  switch_update_interrupt_sense();
}

void check_p2_switches(void)
{
  char p2val = switch_update_interrupt_sense();
  switch1_state = (p2val & SW1) ? 0 : 1;
  switch2_state = (p2val & SW2) ? 0 : 1;
  switch3_state = (p2val & SW3) ? 0 : 1;
  switch4_state = (p2val & SW4) ? 0 : 1;
  redraw_screen = 1;
}
