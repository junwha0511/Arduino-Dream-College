#include <LiquidCrystal_I2C.h>

#define POT_PIN A0

LiquidCrystal_I2C  LCD(0x3F, 16,2);

void setup() {
  Serial.begin(115200);
  LCD.begin(0,0);
  LCD.init();
  LCD.backlight();
  LCD.print("Hello World!");

}
 int val = 0;
void loop() {
  val = analogRead(POT_PIN);
  LCD.clear();
  LCD.print(val);

  Serial.print("Brightness value: ");
  Serial.println(val);

  delay(1000);
}
