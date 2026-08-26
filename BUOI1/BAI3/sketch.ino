const int kPinButton1=2;
const int kPinLed =9;

void setup() {
  // put your setup code here, to run once:
pinMode(kPinButton1, INPUT);
digitalWrite(kPinButton1, HIGH);
pinMode(kPinLed,OUTPUT);

}
void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(kPinButton1)==LOW){
  digitalWrite(kPinLed, HIGH);
}
else{
  digitalWrite(kPinLed, LOW);
}
}
