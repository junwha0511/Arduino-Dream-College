#include <DHT11.h>


#include <LiquidCrystal_I2C.h>
DHT11 dht11(D3);
LiquidCrystal_I2C LCD(0x3F, 16,2);

void setup() {
  LCD.init();
  LCD.backlight();
}

void loop() { 
  float temp, humi;
  int result=dht11.read(humi,temp);
 
  if(result==0){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("T:");
    LCD.print(temp);
    LCD.print(" ");
    //LCD.setCursor(1,0);
    LCD.print("H:");
    LCD.print(humi);

    
   
  } delay(2000);
}
