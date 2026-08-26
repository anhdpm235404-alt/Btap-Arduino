void setup() {
  for (int i = 2; i < 10; i++) {      // Chọn các chân 2-9 làm ngõ ra
    pinMode(i, OUTPUT);
  }
}

// Hàm tắt tất cả các LED tại cùng một thời điểm
void allLEDsOff(void) {
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, LOW);
  }
}

void loop() {
  // Bật sáng lần lượt các LED theo chiều từ trái sang phải
  for (int i = 2; i < 9; i++) {
    allLEDsOff();             // Tắt toàn bộ các LED
    digitalWrite(i, HIGH);    // Bật sáng LED hiện hành
    // Tạo trì hoãn 200 ms, sau đó lặp lại vòng lặp để di chuyển đến LED tiếp theo
    delay(200);
  }
  
  // Bật sáng lần lượt các LED theo chiều ngược lại (từ phải sang trái)
  for (int i = 9; i > 2; i--) {
    allLEDsOff();             // Tắt toàn bộ các LED
    digitalWrite(i, HIGH);    // Bật sáng LED hiện hành
    // Tạo trì hoãn 200 ms
    delay(200);
  }
}