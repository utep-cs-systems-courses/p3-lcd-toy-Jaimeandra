#include <msp430.h>
#include "switches.h"

void port3_c_handler(void){
  if(P2IFG & P2_SWITCHES){
    P2IFG &= ~P2_SWITCHES;
    check_p2_switches();
  }
}
