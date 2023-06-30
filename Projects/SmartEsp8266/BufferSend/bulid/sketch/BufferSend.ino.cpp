#include <Arduino.h>
#line 1 "D:\\Git\\Code-Learning\\Projects\\SmartEsp8266\\BufferSend\\BufferSend.ino"
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0 ,U8X8_PIN_NONE);//实例化

#line 5 "D:\\Git\\Code-Learning\\Projects\\SmartEsp8266\\BufferSend\\BufferSend.ino"
void setup();
#line 11 "D:\\Git\\Code-Learning\\Projects\\SmartEsp8266\\BufferSend\\BufferSend.ino"
void loop();
#line 5 "D:\\Git\\Code-Learning\\Projects\\SmartEsp8266\\BufferSend\\BufferSend.ino"
void setup() {
  u8g2.begin();//初始化
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_wqy12_t_chinese2);
}

void loop() {
  u8g2.setFontDirection(0);
  u8g2.clearBuffer();
  u8g2.setCursor(0,15);
  u8g2.print("不是你2B吧");
  u8g2.setCursor(10,30);
  u8g2.print("Boer是");
  u8g2.setCursor(0,45);
  u8g2.print("那Lisii是不是");
  u8g2.setCursor(10,60);
  u8g2.print("好像是");
  u8g2.sendBuffer();
  delay(10000);
}

