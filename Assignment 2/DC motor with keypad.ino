#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns as this is a 4*4 Keypad

char keys[ROWS][COLS] = {

  {'7', '8', '9', '/'},

  {'4', '5', '6', '*'},

  {'1', '2', '3', '-'},

  {'c', '0', '=', '+'}

}; // defining the keys in the keypad

byte rowPins[ROWS] = { 8, 7, 5, 4 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 3, 2, 1, 0 }; // Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // Create the Keypad variable to identify and store the pressed key.



int EN1 = 13;
int EN2 = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

char KEY = 'n';

void loop() {
// put your main code here, to run repeatedly:
digitalWrite(EN1, HIGH);
digitalWrite(EN2, HIGH);
char key = kpd.getKey(); /// get key from keypad
if (key != 0) {
if (KEY == 'n') {
KEY = key;
} else {
if (key == '1') {
  if (KEY == '1') {
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    delay(2000);
    KEY = 'n';
    digitalWrite(11, LOW);
  } else if (KEY == '2') {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(6, LOW);
    delay(2000);
    digitalWrite(9, LOW);
    KEY = 'n';
  } else if (KEY == '3') {
    // digitalWrite(11, HIGH);
    // digitalWrite(10, LOW);
    //digitalWrite(9, LOW);
    //digitalWrite(6, LOW);
  }
} else {
  if (KEY == '1') {
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    delay(2000);
    digitalWrite(10, LOW);
    KEY = 'n';
  } else if (KEY == '2') {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, HIGH);
    delay(2000);
    KEY = 'n';
    digitalWrite(6, LOW);
} else if (KEY == '3') {
    // digitalWrite(11, HIGH);
    // digitalWrite(10, LOW);
    //digitalWrite(9, LOW);
    // digitalWrite(6, LOW);
  }
}
}
}
}
