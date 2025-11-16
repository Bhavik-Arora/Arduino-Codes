// Buzzer connected to pin 11
int buzzer = 11;

// LEDs connected to pins 2, 3, 4, 5, 6
int leds[] = {2, 3, 4, 5, 6};

// Notes of "Jingle Bells" melody (in Hz)
int melody[] = {
  // Chorus: Jingle Bells, Jingle Bells
  330, 330, 330, 330, 330, 330, 330, 392, 262, 294, 330,
  349, 349, 349, 349, 349, 330, 330, 330, 330, 294, 294, 330, 294, 492,

  // Verse: Dashing through the snow
  392, 392, 392, 392, 392
};

// Duration of each note (milliseconds)
int durations[] = {
  400, 400, 800, 400, 400, 800, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 800,

  400, 400, 400, 400, 400

  
};

void setup() {
  // Set buzzer as output
  pinMode(buzzer, OUTPUT);

  // Set LED pins as outputs
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int totalNotes = sizeof(melody) / sizeof(melody[0]);

  for (int i = 0; i < totalNotes; i++) {
    // Turn off all LEDs
    for (int j = 0; j < 5; j++) {
      digitalWrite(leds[j], LOW);
    }

    // Light up one LED in sequence
    int ledIndex = i % 5;
    digitalWrite(leds[ledIndex], HIGH);

    // Play the note on buzzer
    tone(buzzer, melody[i]);
    delay(durations[i]);

    // Turn off buzzer and LED
    noTone(buzzer);
    digitalWrite(leds[ledIndex], LOW);

    delay(50); // Short pause between notes
  }

  delay(15); // Pause before repeating the whole song
}
