#include <LiquidCrystal_I2C.h>
int sum=0;
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int Button = 14;
void setup() {
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(5, 0);
  Serial.begin(115200); //serial 통신이 속도를 정함

  pinMode(Button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(1){
  int val = digitalRead(Button);
  if(val>=1){
  sum+=1;
  lcd.clear();
  lcd.print("clicked ");
  lcd.print(sum);
  lcd.print("time");
  val=0;
  delay(300);
  }
  }
}
