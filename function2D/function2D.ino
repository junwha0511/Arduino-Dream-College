#include<ESP8266WiFi.h>
#include<ThingSpeak.h>

const char* ssid = "AndroidAP";
const char* password = "00000000";

unsigned long ch1_ID = 376243;
const char* ch1_WriteKey = "R87N7URS4V6E2I8A";
WiFiClient client;

void setup() {
  initWifi();
  ThingSpeak.begin(client);
}

void loop() {
  for(int x=-100; x<100; x++){
    int y=(x+1)*(x+1);
    ThingSpeak.writeField(ch1_ID,1,y,ch1_WriteKey);
    
    delay(3);
  }
}
void initWifi(){
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    }
}
