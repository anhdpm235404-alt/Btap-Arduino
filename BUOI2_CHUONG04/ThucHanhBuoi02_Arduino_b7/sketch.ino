#include "DHT.h"

#define DHTPIN A0      // Khai báo chân DATA nối với A0 theo yêu cầu sách
#define DHTTYPE DHT22  // Sử dụng DHT22 trên Wokwi

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Khởi tạo tốc độ truyền nối tiếp
  Serial.println();
  
  // In ra dòng tiêu đề các cột giống hệt trong sách
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  
  dht.begin();
}

void loop() {
  delay(2000); // Chờ 2 giây giữa các lần đọc

  // Đọc độ ẩm và nhiệt độ
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Kiểm tra xem cảm biến có đọc thành công không (In ra Status)
  if (isnan(humidity) || isnan(temperature)) {
    Serial.print("Error");
  } else {
    Serial.print("OK");
  }

  // In các giá trị ra Serial Monitor kèm khoảng trắng (tab)
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");

  // Đổi sang độ F và in ra
  float fahrenheit = (temperature * 1.8) + 32;
  Serial.println(fahrenheit, 1);
}