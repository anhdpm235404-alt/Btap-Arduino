#include <PololuLedStrip.h>

// Tạo một đối tượng ledStrip và chỉ định chân dữ liệu số 12
PololuLedStrip<12> ledStrip;

// Cài đặt số lượng LED là 32
#define LED_COUNT 32
rgb_color colors[LED_COUNT];

void setup() {
  // Không cần thiết lập gì thêm trong hàm setup
}

// Hàm toán học chuyển đổi màu từ hệ HSV sang RGB
rgb_color hsvToRgb(uint16_t h, uint8_t s, uint8_t v) {
    uint8_t f = (h % 60) * 255 / 60;
    uint8_t p = (255 - s) * (uint16_t)v / 255;
    uint8_t q = (255 - f * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t t = (255 - (255 - f) * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t r = 0, g = 0, b = 0;
    
    switch((h / 60) % 6){
        case 0: r = v; g = t; b = p; break;
        case 1: r = q; g = v; b = p; break;
        case 2: r = p; g = v; b = t; break;
        case 3: r = p; g = q; b = v; break;
        case 4: r = t; g = p; b = v; break;
        case 5: r = v; g = p; b = q; break;
    }
    return (rgb_color) { r, g, b };
}

void loop() {
    // Cập nhật các màu sắc thay đổi liên tục theo thời gian
    uint16_t time = millis() >> 2;
    for (uint16_t i = 0; i < LED_COUNT; i++) {
        byte x = (time >> 2) - (i << 3);
        colors[i] = hsvToRgb((uint32_t)x * 359 / 256, 255, 255);
    }
    
    // Ghi các màu vào dải LED để phát sáng
    ledStrip.write(colors, LED_COUNT);
    delay(10);
}