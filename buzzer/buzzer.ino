const int buzzerPin = 11;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Play a tone at 1000 Hz for 500 milliseconds
  tone(buzzerPin, 1000, 500);
  delay(500);

   tone(buzzerPin, 900, 500);
  delay(450);

  // Stop the tone
    tone(buzzerPin, 800, 500);
  delay(400);

   tone(buzzerPin, 700, 500);
  delay(300);

   tone(buzzerPin, 600, 500);
  delay(200);


 tone(buzzerPin, 500, 500);
  delay(150);

}