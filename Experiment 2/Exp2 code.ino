#include <Keypad.h>
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns as this is a 4*4 Keypad

char keys[ROWS][COLS] = {

  {'7', '8', '9', '/'},

  {'4', '5', '6', '*'},

  {'1', '2', '3', '-'},

  {'c', '0', '=', '+'}

}; // defining the keys in the keypad

byte rowPins[ROWS] = { 13, 12, 11, 10 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 9, 8, 7, 6 }; // Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // Create the Keypad variable to identify and store the pressed key.

char key;
void setup() {
  Serial.begin(9600); // initialize the serial monitor
}

long num1 = 0, num2 = 0, ans = 0;
bool opFirst = true, isFirst = true;
char op = '?';

void loop() {
  char key = kpd.getKey();
  if (key != 0) {
    Serial.print("Button Pressed ");
    Serial.println(key);
    if (key == 'c') {
      Serial.println("Reset Calculator");
      reset();
    }
    else if (key >= '0' and key <= '9') {
      if (isFirst) {
        num1 = (num1 * 10) + (key - '0');
        opFirst = false;
      } else {
        num2 = (num2 * 10) + (key - '0');
      }
    } else if (key == '=') {
      if (op == '?') {
        Serial.println("No operation");
      } else {
        bool ck = true;
        if (op == '+') ans = num1 + num2;
        else if (op == '-') ans = num1 - num2;
        else if (op == '*') ans = num1 * num2;
        else if (op == '/' and num2 != 0) ans = num1 / num2;
        else ck = false;  
        if(!ck) Serial.println("Divion by zero is undefined");
        else{
          Serial.print("Result = ");
          Serial.println(ans);
          delay(100);
          Serial.println("Calculator Reset");
        }
        reset();
      }
    } else {
      if(!opFirst) op = key, isFirst = false;
      else Serial.println("No opeartion");
    }
  }
}

void reset() {
  num1 = num2 = ans = 0;
  opFirst = true;
  isFirst = true;
  op = '?';
}
