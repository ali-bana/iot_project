#include "U8glib.h"
U8GLIB_NHD_C12864 u8g(13, 11, 10, 9, 8);	// SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8

#define u8g_logo_width 64
#define u8g_logo_height 64
//static unsigned char u8g_logo_bits[] = {
static unsigned char u8g_logo_bits[] U8G_PROGMEM = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x80, 0x8f, 0xc7, 0x00, 0x00, 0xfc,
   0x1f, 0x00, 0x80, 0x8f, 0xc7, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x80, 0x8f,
   0xc7, 0x00, 0x00, 0xfc, 0x1f, 0xff, 0x8f, 0xf1, 0xf1, 0xf8, 0x7f, 0xfc,
   0x1f, 0xff, 0x8f, 0xf1, 0xf1, 0xf8, 0x7f, 0xfc, 0x1f, 0x03, 0x8c, 0x81,
   0xf1, 0x18, 0x60, 0xfc, 0x1f, 0x03, 0x8c, 0x8f, 0xff, 0x18, 0x60, 0xfc,
   0x1f, 0x03, 0x8c, 0x8f, 0xff, 0x18, 0x60, 0xfc, 0x1f, 0x03, 0x8c, 0xf1,
   0xf1, 0x18, 0x60, 0xfc, 0x1f, 0x03, 0x8c, 0xf1, 0xf1, 0x18, 0x60, 0xfc,
   0x1f, 0x03, 0x8c, 0x31, 0xc0, 0x18, 0x60, 0xfc, 0x1f, 0x03, 0x8c, 0x3f,
   0xc6, 0x18, 0x60, 0xfc, 0x1f, 0x03, 0x8c, 0x3f, 0xc6, 0x18, 0x60, 0xfc,
   0x1f, 0xff, 0x8f, 0x01, 0xc6, 0xf8, 0x7f, 0xfc, 0x1f, 0xff, 0x8f, 0x01,
   0xc6, 0xf8, 0x7f, 0xfc, 0x1f, 0x00, 0x80, 0x01, 0xc6, 0x00, 0x00, 0xfc,
   0x1f, 0x00, 0x80, 0x31, 0xc6, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x80, 0x31,
   0xc6, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x3f, 0xc0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x3f, 0xc0, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x0c, 0x00,
   0x00, 0xc6, 0x18, 0xff, 0x1f, 0x00, 0x0c, 0x80, 0x31, 0xc6, 0x18, 0xff,
   0x1f, 0x00, 0x0c, 0x80, 0x31, 0xc6, 0x18, 0xff, 0xff, 0x18, 0x7f, 0x3c,
   0x3e, 0x06, 0x00, 0xfc, 0xff, 0x18, 0x7f, 0x3c, 0x3e, 0x06, 0x00, 0xfc,
   0x1f, 0x18, 0x03, 0x0c, 0x00, 0x00, 0x00, 0xfc, 0x1f, 0xff, 0x03, 0x0c,
   0x00, 0xf8, 0x18, 0xff, 0x1f, 0xff, 0x03, 0x0c, 0x00, 0xf8, 0x18, 0xff,
   0xff, 0x63, 0x7c, 0x8c, 0xf1, 0xc7, 0x00, 0xfc, 0xff, 0x63, 0x7c, 0x8c,
   0xf1, 0xc7, 0x00, 0xfc, 0xff, 0x03, 0x00, 0x80, 0x31, 0xc0, 0x00, 0xfc,
   0xff, 0x1f, 0x80, 0x81, 0x31, 0xc0, 0x18, 0xff, 0xff, 0x1f, 0x80, 0x81,
   0x31, 0xc0, 0x18, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0x18, 0x00, 0xfc,
   0xff, 0xff, 0xff, 0xf1, 0xff, 0x18, 0x00, 0xfc, 0x1f, 0x00, 0x80, 0x31,
   0x00, 0x18, 0x00, 0xfc, 0x1f, 0x00, 0x80, 0x31, 0x00, 0xf8, 0x18, 0xff,
   0x1f, 0x00, 0x80, 0x31, 0x00, 0xf8, 0x18, 0xff, 0x1f, 0xff, 0x8f, 0xff,
   0x31, 0xc6, 0x63, 0xfc, 0x1f, 0xff, 0x8f, 0xff, 0x31, 0xc6, 0x63, 0xfc,
   0x1f, 0x03, 0x8c, 0x31, 0x00, 0xc0, 0x03, 0xfc, 0x1f, 0x03, 0x8c, 0x31,
   0xc6, 0xc0, 0x1f, 0xfc, 0x1f, 0x03, 0x8c, 0x31, 0xc6, 0xc0, 0x1f, 0xfc,
   0x1f, 0x03, 0x8c, 0x31, 0x3e, 0x1e, 0xf8, 0xff, 0x1f, 0x03, 0x8c, 0x31,
   0x3e, 0x1e, 0xf8, 0xff, 0x1f, 0x03, 0x8c, 0x31, 0x00, 0x1e, 0xf8, 0xff,
   0x1f, 0x03, 0x8c, 0x31, 0x00, 0xfe, 0xf8, 0xff, 0x1f, 0x03, 0x8c, 0x31,
   0x00, 0xfe, 0xf8, 0xff, 0x1f, 0xff, 0x8f, 0x31, 0xfe, 0x1f, 0xe0, 0xff,
   0x1f, 0xff, 0x8f, 0x31, 0xfe, 0x1f, 0xe0, 0xff, 0x1f, 0x00, 0x80, 0x31,
   0xf0, 0x18, 0x00, 0xff, 0x1f, 0x00, 0x80, 0xf1, 0xf1, 0xf8, 0x1f, 0xff,
   0x1f, 0x00, 0x80, 0xf1, 0xf1, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff   };

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.drawXBMP( 0, 0, u8g_logo_width, u8g_logo_height, u8g_logo_bits);
}

void setup(void) {
  // flip screen, if required
  // u8g.setRot180();
}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(500);
}
