
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int flag=0;
void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  
}

void loop() {
 lcd.clear();
 lcd.print("Hi");
 delay(1000);
 lcd.clear();
 delay(100);
 lcd.print("Hello");
 delay(1000);
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


