// Buzzer connected to pin 11
int buzzer = 11;

// LEDs on pins 2, 3, 4, 5, 6
int leds[] = {2, 3, 4, 5, 6};

// Notes for "Happy Birthday"
int notes[] = {
  262, 262, 294, 262, 349, 330,
  262, 262, 294, 262, 392, 349,
  262, 262, 523, 440, 349, 330, 294,
  466, 466, 440, 349, 392, 349
};

// Duration of each note (milliseconds)
int durations[] = {
  500, 250, 500, 500, 500, 1000,
  500, 250, 500, 500, 500, 1000,
  500, 250, 500, 500, 500, 500, 1000,
  500, 250, 500, 500, 500, 1000
};

void setup() {
  // Set buzzer as output
  pinMode(buzzer, OUTPUT);
  
  // Set all LED pins as output
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 26; i++) {
    // Turn off all LEDs first
    for (int j = 0; j < 5; j++) {
      digitalWrite(leds[j], LOW);
    }

    // Select which LED to light (cycling through 5 LEDs)
    int ledIndex = i % 5;
    digitalWrite(leds[ledIndex], HIGH);

    // Play the note
    tone(buzzer, notes[i]);
    delay(durations[i]);

    // Turn off current LED and stop buzzer
    digitalWrite(leds[ledIndex], LOW);
    noTone(buzzer);

    delay(100); // Short pause between notes
  }

  delay(3000); // Pause before melody restarts
}
