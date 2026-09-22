#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 2;
const int LED_PIN = 13;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("Da sang sang nhan tin hieu IR...");
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long command = IrReceiver.decodedIRData.command;
    
    Serial.print("Ma Command: 0x");
    Serial.println(command, HEX);

    // Nut 1 tren Remote Wokwi (Command: 0x30) -> Bat LED
    if (command == 0x30) {        
      digitalWrite(LED_PIN, HIGH);
      Serial.println("-> BAT LED");
    } 
    // Nut 2 tren Remote Wokwi (Command: 0x18) -> TAT LED
    else if (command == 0x18) {   
      digitalWrite(LED_PIN, LOW);
      Serial.println("-> TAT LED");
    }

    IrReceiver.resume(); 
  }
}