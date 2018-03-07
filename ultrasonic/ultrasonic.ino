#include <LiquidCrystal_I2C.h>

int trigPin=D9;
int echoPin=D8;

LiquidCrystal_I2C  LCD(0x3F, 16,2);

void setup() {
  pinMode(trigPin, OUTPUT);
   LCD.begin(0,0);
  LCD.init();
  LCD.backlight();
  LCD.print("Hello World!");
}

void loop() {
  LCD.clear();
  float duration,distance;
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);

  duration= pulseIn(echoPin, HIGH);
  distance=((float)(340*duration)/10000)/2;
  LCD.setCursor(0,0);
  LCD.print(duration);
  LCD.setCursor(1,0);
  LCD.print(distance);

  delay(10000); 
}
