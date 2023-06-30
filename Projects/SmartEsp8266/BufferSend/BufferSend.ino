#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0 ,U8X8_PIN_NONE);//实例化

void setup() {
  u8g2.begin();//初始化
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_unifont_t_symbols);
}

void loop() {
  u8g2.firstPage();
  do
  {
  u8g2.drawStr(0, 32, "drawTriangle");
  u8g2.drawTriangle(14,32, 45,60, 9,42);  
  }while(u8g2.nextPage());
}
