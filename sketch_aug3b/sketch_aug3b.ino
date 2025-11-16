#include <Servo.h>

// Define pins
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 3; // optional LED
const int thresholdDistance = 15; // distance in cm

Servo gateServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  gateServo.attach(6); // Servo connected to pin 6
  gateServo.write(0);  // Start with gate closed
}

void loop() {
  long duration;
  int distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance (in cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < thresholdDistance) {
    digitalWrite(ledPin, HIGH);
    gateServo.write(90);  // Open gate
    delay(5000);          // Keep open for 3 seconds
    gateServo.write(0);   // Close gate
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
