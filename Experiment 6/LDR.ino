
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int x = analogRead(A0);
  // print out the value you read:
  Serial.println(x);
  double voltage = x * 5 / 1023.0 ;
  if(voltage > 2.5){
    digitalWrite(13, HIGH);
  }else digitalWrite(13, LOW);
  Serial.println(voltage);
  delay(2000);        // delay in between reads for stability
}
