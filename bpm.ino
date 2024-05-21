const int sensorPin = A0;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  int bpm = map(sensorValue, 0, 1023, 40, 200);
  
  Serial.print("Heart Rate: ");
  Serial.print(bpm);
  Serial.println(" BPM");
  
  blinkLED(bpm);
  
  delay(1000);
}

void blinkLED(int bpm) {
  int blinkInterval = 60000 / bpm;
  digitalWrite(ledPin, HIGH);
  delay(blinkInterval / 2);
  digitalWrite(ledPin, LOW);
  delay(blinkInterval / 2);
}
