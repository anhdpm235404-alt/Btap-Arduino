#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Servo.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
#define WIFI_CHANNEL 6

// Cấu hình MQTT Broker
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "agu/iot/dongho/time";

WiFiClient espClient;
PubSubClient client(espClient);

// Khai báo 6 chân điều khiển Servo
const int servoPins[6] = {13, 12, 14, 27, 26, 25};
Servo servos[6];

// Hàm callback xử lý khi nhận được dữ liệu từ Broker (Trang 215)[cite: 494, 495]
void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Nhan du lieu MQTT: ");
  Serial.println(message);

  // Phân tách chuỗi "HH:MM:SS" thành 6 chữ số hàng chục và đơn vị
  if (message.length() >= 8) {
    int digits[6];
    digits[0] = message.charAt(0) - '0'; // Chục giờ
    digits[1] = message.charAt(1) - '0'; // Đơn vị giờ
    digits[2] = message.charAt(3) - '0'; // Chục phút
    digits[3] = message.charAt(4) - '0'; // Đơn vị phút
    digits[4] = message.charAt(6) - '0'; // Chục giây
    digits[5] = message.charAt(7) - '0'; // Đơn vị giây

    // Điều khiển 6 Servo quay đến góc tương ứng (0 - 180 độ)
    for (int i = 0; i < 6; i++) {
      int angle = map(digits[i], 0, 9, 0, 180);
      servos[i].write(angle);
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Dang ket noi MQTT Subscriber...");
    String clientId = "ESP32-Subscriber-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println(" Thanh cong!");
      // Đăng ký nhận dữ liệu từ Topic bằng hàm subscribe() (Trang 215)[cite: 494, 495]
      client.subscribe(mqtt_topic);
    } else {
      Serial.print(" Loi rc=");
      Serial.print(client.state());
      Serial.println(" Thu lai sau 2 giay...");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  // Gắn chân cho 6 Servo
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(0);
  }

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL);
  Serial.print("Dang ket noi WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Da ket noi WiFi!");

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback); // Gắn hàm callback nhận dữ liệu (Trang 215)[cite: 494, 495]
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop(); // Duy trì vòng lặp lắng nghe tin nhắn MQTT từ Broker (Trang 216)[cite: 494, 495]
}