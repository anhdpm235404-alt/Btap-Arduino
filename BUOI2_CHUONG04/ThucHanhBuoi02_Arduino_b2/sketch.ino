int irPin = 8;
int ledPin = 13;
int objectDetected = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(irPin, INPUT);
  // Kích hoạt điện trở treo bên trong
  digitalWrite(irPin, HIGH);
}

void loop() {
  objectDetected = digitalRead(irPin);
  
  // Nếu cảm biến trả về LOW (phát hiện vật cản) -> Bật đèn LED
  if (LOW == objectDetected) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}