#include <Keypad.h>
#include <LiquidCrystal.h>

/// connected pin with lcd and arduino
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns as this is a 4*4 Keypad

char keys[ROWS][COLS] = {

  {'7', '8', '9', '/'},

  {'4', '5', '6', '*'},

  {'1', '2', '3', '-'},

  {'c', '0', '=', '+'}

}; // defining the keys in the keypad

byte rowPins[ROWS] = { 7, 6, 5, 4 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 3, 2, 1, 0 }; // Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // Create the Keypad variable to identify and store the pressed key.

long num1 = 0, num2 = 0, ans = 0;
bool opFirst = true, isFirst = true, okSecond = false, done = false;
char op = '?';


void setup() {
  lcd.begin(20, 2);//set up the LCD's number of column and rows
}

void loop() {
  cal();
}
void cal() {
  char key = kpd.getKey(); /// get key from keypad
  if (key != 0) {
    if(!done)lcd.print(key); // if result is not calculated
    if (key == 'c') { /// c for reset
      lcd.setCursor(0, 1);
      lcd.print("Reset Calculator");
      delay(500);
      reset();
    }
    else if (key >= '0' and key <= '9') { /// genarating number
      if (isFirst) {
        num1 = (num1 * 10) + (key - '0');
        opFirst = false;
      } else {
        num2 = (num2 * 10) + (key - '0');
        okSecond = true;
      }
    } else if (key == '=') { /// if want to know ans
      lcd.setCursor(0, 1);
      if (op == '?' or !okSecond) {
        lcd.print("Error!!!");
        delay(100);
        reset();
      } else {
        bool ck = true;
        if (op == '+') ans = num1 + num2;
        else if (op == '-') ans = num1 - num2;
        else if (op == '*') ans = num1 * num2;
        else if (op == '/' and num2 != 0) ans = num1 / num2;
        else ck = false;
        if (!ck) lcd.print("Undefined");
        else {
          lcd.print(ans);
        }
        done = true;
      }
    } else { /// if someone pressed opeation key
      if (!opFirst and op == '?') op = key, isFirst = false; /// setting operation
      else{
        lcd.print("Invalid");
        delay(300);
        lcd.clear();
        reset();
      } /// if any invaild input found
    }
  }
}

void reset() { // reset function
  num1 = num2 = ans = 0;
  opFirst = true;
  isFirst = true;
  okSecond = false;
  done = false;
  op = '?';
  lcd.clear();
  lcd.setCursor(0, 0);
}
