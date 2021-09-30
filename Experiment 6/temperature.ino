void setup() {
  // initialize serial communication at 9600 bits per second:
   Serial.begin(9600);
   pinMode(13, OUTPUT);
}


// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int x = analogRead(A1);
  // print out the value you read:
  int temp = ((5* x * 100) / 1023) ;
  if (temp>27)
  {
    digitalWrite(13, HIGH);
    
  }
  if (temp <= 27)
  {
    digitalWrite(13, LOW);
  }
  Serial.println(temp);
  
  delay(500);
  
  // delay in between reads for stability
}
