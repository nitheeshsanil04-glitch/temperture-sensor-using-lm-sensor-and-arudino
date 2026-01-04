// LM35 pin
int tempPin = A0;

// LED pins (same order as your wiring)
int ledPins[7] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  // Set LED pins as OUTPUT
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Read LM35 value
  int sensorValue = analogRead(tempPin);

  // Convert to voltage (5V reference)
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert voltage to temperature (LM35: 10mV per °C)
  float temperature = voltage * 100;

  // Turn OFF all LEDs first
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Turn ON LEDs based on temperature
  if (temperature >= 20) digitalWrite(ledPins[0], HIGH);
  if (temperature >= 50) digitalWrite(ledPins[1], HIGH);
  if (temperature >= 75) digitalWrite(ledPins[2], HIGH);
  if (temperature >= 90) digitalWrite(ledPins[3], HIGH);
  if (temperature >= 100) digitalWrite(ledPins[4], HIGH);
  if (temperature >= 120) digitalWrite(ledPins[5], HIGH);
  if (temperature >= 150 ) digitalWrite(ledPins[6], HIGH);

  delay(500);
}
