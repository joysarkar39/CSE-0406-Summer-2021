
double x = 0.0, y = 0.0, now;
void setup() {
  Serial.begin(9600); // initialize the serial monitor
  pinMode(A0,INPUT);
}

void loop() {
   x = analogRead(A0);
   now = (5.0/1023.0)*x; /// as 5V == 1023
   Serial.print(now);
   Serial.println(" Voltage");
   delay(2000);
}
