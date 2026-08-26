const int kPinButton1 =2;
const int kPinButton2 =3;
const int kPinLed=9;

void setup() {
  // put your setup code here, to run once:
pinMode(kPinButton1, INPUT );
pinMode(kPinButton2, INPUT );
pinMode(kPinLed, OUTPUT );
digitalWrite(kPinButton1, HIGH);
digitalWrite(kPinButton2, HIGH);
}
int ledBrightness =128;


void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(kPinButton1)==LOW){
  ledBrightness--;

}else if(digitalRead(kPinButton2)==LOW){
  ledBrightness++;
}
ledBrightness=constrain(ledBrightness, 0,255);
analogWrite(kPinLed, ledBrightness);
delay(20);
}
