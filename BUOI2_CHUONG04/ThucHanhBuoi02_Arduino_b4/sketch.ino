const int LDR_PIN = A0;
const int LED_PIN = 13;
const int THRESHOLD = 500; // Ngưỡng ánh sáng kích hoạt

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(LDR_PIN);
  Serial.print("Gia tri cam bien AO: ");
  Serial.println(sensorValue);

  // Khi troi toi (gia tri dien ap tang cao tren chân AO)
  if (sensorValue > THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // Bat LED
  } else {
    digitalWrite(LED_PIN, LOW);  // Tat LED
  }
  delay(100);
}