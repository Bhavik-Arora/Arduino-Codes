  // C++ code
//
void setup()
{a
  pinMode(4, OUTPUT):
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT); 
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}

void loop()
{
  int a= digitalRead(7);
  if(a==0){
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
}
  else{
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  }
  int b= digitalRead(8);
  if(b==0){
    digitalWrite(6,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
}