#ifndef led_included
#define led_included

#define LED_RED 0
#define LED_GREEN BIT6
#define LEDS (LED_RED | LED_GREEN)

extern unsigned char red_on, green_on;
extern unsigned char led_changed;

void led_init(void);
void led_update(void);

#endif
