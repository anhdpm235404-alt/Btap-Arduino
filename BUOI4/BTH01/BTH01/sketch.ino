#include <ESP32Servo.h>

#define SERVO_COUNT 6

int servoPins[SERVO_COUNT] = {13, 12, 14, 27, 26, 25};
Servo myservo[SERVO_COUNT];

int potPinHour = 34;
int potPinMin  = 35;
int potPinSec  = 32;

// Biến lưu giá trị cũ để chỉ in bảng khi bạn vặn biến trở
int lastGio = -1, lastPhut = -1, lastGiay = -1;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < SERVO_COUNT; i++) {
    myservo[i].attach(servoPins[i]);
  }
  Serial.println("==========================================================================");
  Serial.println("| THOI GIAN | CHUC GIO | D.VI GIO | CHUC PHUT | D.VI PHUT | CHUC GIAY | D.VI GIAY |");
  Serial.println("==========================================================================");
}

void loop() {
  int gio  = map(analogRead(potPinHour), 0, 4095, 0, 23);
  int phut = map(analogRead(potPinMin),  0, 4095, 0, 59);
  int giay = map(analogRead(potPinSec),  0, 4095, 0, 59);

  // Chỉ cập nhật và in bảng khi giá trị Giờ, Phút hoặc Giây thay đổi
  if (gio != lastGio || phut != lastPhut || giay != lastGiay) {
    lastGio = gio;
    lastPhut = phut;
    lastGiay = giay;

    int digits[6] = {
      gio / 10,  gio % 10,
      phut / 10, phut % 10,
      giay / 10, giay % 10
    };

    int angles[6];
    for (int i = 0; i < SERVO_COUNT; i++) {
      angles[i] = map(digits[i], 0, 9, 0, 180);
      myservo[i].write(angles[i]);
    }

    // In dòng kết quả dạng bảng căn cột thẳng hàng
    Serial.printf("|  %02d:%02d:%02d | %d (%3d°) | %d (%3d°) |  %d (%3d°) |  %d (%3d°) |  %d (%3d°) |  %d (%3d°) |\n",
                  gio, phut, giay,
                  digits[0], angles[0],
                  digits[1], angles[1],
                  digits[2], angles[2],
                  digits[3], angles[3],
                  digits[4], angles[4],
                  digits[5], angles[5]);
  }

  delay(50);
}