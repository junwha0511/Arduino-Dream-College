#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

#include<SoftwareSerial.h>
#include<stdlib.h>
#define DEBUG true;

int ulPin=D4;
void setup() {
}

void loop() {
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
 
  delay(500);
}


long mtocm(long a){
  return a/29/2;
}
long mtoinch(long b){
  return b/74/2;
}
