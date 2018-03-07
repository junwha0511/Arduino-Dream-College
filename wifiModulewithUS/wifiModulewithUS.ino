th#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
const char* ssid = "AndroidAP";
const char* password = "00000000";
WiFiClient client;

unsigned long ch1_ID = 361568;
const char* ch1_WriteKey = "HL1Q9M4M9DK4Z7OO";
int ulPin=D4;
void setup() {
  lcd.init();
  lcd.backlight();
  delay(10);
  initWifi();
  ThingSpeak.begin(client);
}

void loop() {
  lcd.clear();
  pinMode(ulPin,OUTPUT);
  digitalWrite(ulPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ulPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ulPin,LOW);

  pinMode(ulPin,INPUT);
  long duration = pulseIn(ulPin, HIGH);

  long cm = mtocm(duration);
  long inch = mtoinch(duration);
  lcd.setCursor(0,0);
  lcd.print(cm);
  lcd.print("cm");
  lcd.setCursor(0,1);
  lcd.print(inch);
  lcd.print("inch");
  //int intnum = (int)cm;
  int num=(int)cm;
  ThingSpeak.writeField(ch1_ID,1,cm,ch1_WriteKey);
  delay(500);
}


long mtocm(long a){
  return a/29/2;
}
long mtoinch(long b){
  return b/74/2;
}

void initWifi(){
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    lcd.clear();
    lcd.print("no connect");
    }
}

