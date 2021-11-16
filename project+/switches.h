#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define P2_SWITCHES (SW1 | SW2 | SW3 | SW4) // use all the switches

void switch_p2_init(void);
void check_p2_switches(void);

extern const char down;
extern const char up;

extern char switch1_state, switch2_state,switch3_state,switch4_state;

#endif
