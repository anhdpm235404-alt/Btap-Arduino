const int PIR_PIN = 2;     // Chân đọc tín hiệu từ cảm biến PIR
const int LED_PIN = 13;    // Đèn LED báo hiệu
const int BUZZER_PIN = 8;  // Còi báo động

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Đang khởi động cảm biến PIR...");
}

void loop() {
  int pirState = digitalRead(PIR_PIN);

  if (pirState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000); // Phát âm thanh 1000Hz
    Serial.println("--> Phát hiện chuyển động!");
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    Serial.println("An toàn - Không có chuyển động.");
  }
  
  delay(200);
}