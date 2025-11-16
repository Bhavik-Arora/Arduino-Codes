int trigPin =7;
int echoPin = 6;
long duration;
int distance;


void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW); 
}

  
void loop() {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 duration = pulseIn(echoPin,HIGH);
 distance = duration * 0.034 / 2;
 delay(50);
 Serial.print("Distance: ");
 Serial.println(distance);
  
  if(distance<20){
  digitalWrite(11, HIGH);
 }
  else if (20<distance<30) {
     digitalWrite(11,LOW);
     digitalWrite(12,HIGH);
  }
  else if (30<distance<40) {
    digitalWrite(12,LOW); 
      digitalWrite(13,HIGH);
     
  }
 else if (40<distance<50) {
     digitalWrite(11,HIGH);
      digitalWrite(12,HIGH); 
      digitalWrite(13,LOW);

 }
 else if (50<distance<60) {
   digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
    
 } 
 else if (60<distance<70) {
      digitalWrite(13,HIGH);
 }   
 else if (70<distance<80) {
      digitalWrite(13,HIGH);
       
 }
}


