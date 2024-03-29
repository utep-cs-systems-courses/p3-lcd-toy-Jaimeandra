#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
#include "led.h"

char redraw_screen = 1;
u_int backgroundColor = COLOR_BLUE;

void update_text(void)
{
  const u_char text_row = 20;
  const u_char text_col = 40;
  const u_char char_width = 12;
  static u_char blue = 31, green = 16, red = 31;
  u_int on_color = (green << 5) | red;
  u_int off_color = (blue << 11) | red;

  if(switch1_state == down){
    drawChar5x7(text_col+ char_width, text_row,'1',on_color,backgroundColor);
  }
  else{
    drawChar5x7(text_col + char_width, text_row, '-',on_color, backgroundColor);
  }
  if(switch2_state == down){
    drawChar5x7(text_col + char_width*2, text_row, '2',on_color, backgroundColor);
  }
  else{
    drawChar5x7(text_col + char_width*2, text_row,'-',off_color, backgroundColor);
  }
   if(switch3_state == down){
    drawChar5x7(text_col + char_width*3, text_row, '3',on_color, backgroundColor);
  }
  else{
    drawChar5x7(text_col + char_width*3, text_row,'-',off_color, backgroundColor);
  }
  if(switch4_state == down){
    drawChar5x7(text_col + char_width*4, text_row, '4',on_color, backgroundColor);
  }
  else{
    drawChar5x7(text_col + char_width*4, text_row, '-',on_color, backgroundColor);
    }
}
  
void main(void){
  configureClocks();
  led_init();//
  switch_p2_init();//
  lcd_init();

  or_sr(0x8);

  clearScreen(backgroundColor);

  while(1){
    if(redraw_screen){
      redraw_screen = 0;
      update_text();
    }
    red_on = 0;//
    led_changed = 1;//
    // led_update();//
    or_sr(0x10);
    
    red_on = 1;
    led_changed = 1;
    //    led_update();
  }
}
