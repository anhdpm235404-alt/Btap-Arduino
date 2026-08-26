const int kPinPot =A0;
const int kPinLed =9;

void setup() {
  // put your setup code here, to run once:
//pinMode(kPinPot, INPUT );
pinMode(kPinLed, OUTPUT);

}
long lastTime =0;
int ledValue = LOW;

void loop() {
  // put your main code here, to run repeatedly:
//int ledBrightness;
//int sensorValue=0;
//sensorValue = analogRead(kPinPot);
//ledBrightness = map(sensorValue, 0,1023,0,255);
//analogWrite(kPinLed, ledBrightness);

int sensorValue = analogRead(kPinPot);
if(millis()>lastTime + sensorValue){
  if (ledValue==LOW){
    ledValue = HIGH;
  }
    else{
      ledValue =LOW;
    }
    lastTime = millis();
    digitalWrite(kPinLed, ledValue);
  }
    
}

