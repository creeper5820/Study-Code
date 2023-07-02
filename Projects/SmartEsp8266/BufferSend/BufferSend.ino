#include <Keypad.h>


// the keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {13, 12, 14, 2};
byte colPins[COLS] = {0, 9, 10, 16};
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);



void setup() 
{
  Serial.begin(9600);
  Serial.println("Begin");
}

void loop() 
{
char key = customKeypad.getKey();

    while (key)
    {

      Serial.println(key);
      key = 0;
    }
}
