#line 1 "D:\\Git\\Code-Learning\\Projects\\SmartEsp8266\\Smart\\bulid\\sketch\\Support.h"
#line 1 "D:\\Git\\Code-Learning\\Projects\\SmartEsp8266\\Smart\\Support.h"
// the keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'R', 'L', 'D', '0'},
    {'2', '1', 'U', '0'},
    {'0', '0', '0', '0'},
    {'0', '0', '0', '0'}};
byte rowPins[ROWS] = {12, 13, 3, 9};
byte colPins[COLS] = {0, 2, 14, 15};
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);



// the u8g2
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
