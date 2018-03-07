
#include <LiquidCrystal_I2C.h>
#include <Wire.h>      
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int button=7;
int flag=0;
void setup() {
  pinMode(button, INPUT);
  lcd.init();
  lcd.backlight();

  //lcd.setCursor(0, 0);
  
}

void loop() {
 lcd.setCursor(6,0);
 lcd.print("777");
 while(true){
  if(digitalRead(button)==HIGH){
    while(true){
      for(int i=0;i<9;i++){
        if(digitalRead(button)==HIGH){
          int f = random(9);
          int s = random(9);
          int t = random(9);
          lcd.clear();
          lcd.setCursor(6,0);
          lcd.print(f);
          lcd.print(s);
          lcd.print(t);
          break;
        }
        lcd.clear();
        lcd.setCursor(6,0);
        lcd.print(i);
        lcd.print(i);
        lcd.print(i);
        delay(10);
      }
    }
    break;
  }
  }
 }
  /* if(val>0){
    Serial.print("button push: ");
    Serial.println(val);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3, LOW);
  }else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3,HIGH);

  } */


