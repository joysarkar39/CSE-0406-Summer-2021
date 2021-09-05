#define dw digitalWrite
#define aw analogWrite

int EN1 = 13;
int EN2 = 12;
void setup() {
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT); 

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  dw(EN1, HIGH);
  dw(EN2, HIGH);
  forward();
}

void off(int p1, int p2){
  dw(p1, LOW);
  dw(p2, LOW);
}

void on(int p1, int p2){
  aw(p1, HIGH);
  aw(p2, LOW);
}

void onSpeed(int p1, int p2, int spd){
  aw(p1, spd);
  aw(p2, 0);
}
///Analog Range 0-255

void forward(){
  onSpeed(9, 10, 100);
  onSpeed(5, 6, 255);
  delay(2000);
  onSpeed(10,9, 255);
  onSpeed(6, 5, 100);
  delay(2000);
}
