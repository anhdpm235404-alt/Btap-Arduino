const int GAS_PIN = A0;
const int LED_PIN = 13;
const int BUZZER_PIN = 8;
const int THRESHOLD = 400; // Ngưỡng nồng độ khói kích hoạt báo động

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(GAS_PIN);
  Serial.print("Nồng độ khói: ");
  Serial.println(gasValue);

  if (gasValue > THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000); // Bật còi với tần số 1000Hz
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);     // Tắt còi
  }
  delay(200);
}