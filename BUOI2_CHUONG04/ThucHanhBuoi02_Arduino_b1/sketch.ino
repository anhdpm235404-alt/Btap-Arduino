const int sensor=A1;     // Gán chân analog A1 làm biến 'sensor'
float tempc;             // Biến lưu giá trị nhiệt độ tính theo độ C
float tempf;             // Biến lưu giá trị nhiệt độ tính theo độ F
float vout;              // Biến tạm thời chứa kết quả phép đọc

void setup() 
{
  pinMode(sensor, INPUT); // Cấu hình chân A1 làm ngõ vào
  Serial.begin(9600);
}

void loop() 
{
  vout = analogRead(sensor);
  vout = (vout * 500) / 1023;
  
  tempc = vout;                // Lưu kết quả tính theo độ C
  tempf = (vout * 1.8) + 32;   // Chuyển đổi từ độ C sang độ F
  
  Serial.print("in DegreeC=");
  Serial.print("\t");
  Serial.print(tempc);
  Serial.println();
  
  Serial.print("in Fahrenheit=");
  Serial.print("\t");
  Serial.print(tempf);
  Serial.println();
  
  delay(1000); // Trì hoãn 1 giây để dễ đọc kết quả
}