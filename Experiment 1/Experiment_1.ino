#define dw digitalWrite
#define dr digitalRead
void setup(){
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,INPUT_PULLUP); ///this means 1st value will high
}

void loop(){
  int val = dr(11); /// when push button it will return 0 as we set initial 1
  if(val){
    dw(13,LOW);
    dw(12,LOW);
  }else{
    dw(13,HIGH);
    delay(250);
    dw(12,HIGH);
    delay(250);
  }
}
