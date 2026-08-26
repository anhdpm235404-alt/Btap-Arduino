int redPin =11;
int greenPin = 10;
int bluePin =9;

void setup() {
  // put your setup code here, to run once:
setRgb(0,0,0);
pinMode(redPin, OUTPUT );
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
int Rgb[3];
Rgb[0]=255;
Rgb[1]=0;
Rgb[2]=0;
for(int decrease =0; decrease <3; decrease+=1){
  int increase =(decrease ==2) ?0: decrease +1;
  for(int i=0; i<255; i+=1){
    Rgb[decrease]-=1;
    Rgb[increase]+=1;
    setRgb(Rgb[0],Rgb[1],Rgb[2]);
    delay(20);
  }
}
}
void setRgb(int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
