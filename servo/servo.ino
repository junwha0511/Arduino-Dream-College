/*
   Created by Vasilakis Michalis // 26-12-2014 ver.1
   Project: Control RC Boat / Vessel via Bluetooth with Android Smartphone
   http://www.ardumotive.com/arduino-boat
   More information at www.ardumotive.com
*/
#include <Servo.h>
int servoPin = 9;
int motor  = A3;
Servo servo;
int state;
int angle = 0; // servo position in degrees
//Bluetooth (HC-06 JY-MCU) State pin on pin 2 of Arduino
const int BTState = 2;
int vSpeed = 250;

int enablePin = 10;
int in1Pin = 11;
int in2Pin = 12;

boolean bReverse = true;

int nSpeed = 70;
String sMeg = "Switch : ";



void setup() {
  pinMode(2, INPUT);
  servo.attach(servoPin);
  servo.write(90);
  Serial.begin(9600);
}

void loop() {
  servo.write(90);
  analogWrite(enablePin, nSpeed);
  //Stop boat when connection lost or bluetooth disconnected
  if (digitalRead(BTState) == LOW) {
    state = 'S';
  }

  //Save income data to variable 'state'
  if (Serial.available() > 0) {
    state = Serial.read();
  }
  Serial.println('1');
  /***********************Forward****************************/
  //If state is equal with letter 'F', boat will go forward!
  if (state == 'F') {
      analogWrite(enablePin, true); 
      }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', boat will go forward left
  else if (state == 'G') {

  }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', boat will go forward right
  else if (state == 'I') {

  }
  /***********************Backward****************************/
  //If state is equal with letter 'B', boat will go backward
  else if (state == 'B') {
    analogWrite(enablePin, nSpeed);
  }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', boat will go backward left
  else if (state == 'H') {

  }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', boat will go backward right
  else if (state == 'J') {

  }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
  else if (state == 'L') {
     servo.write(15);
      delay(300);
  }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
  else if (state == 'R') {
    servo.write(-15);
     delay(300);
     Serial.println('HI');
  }

  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the boat
  else if (state == 'S') {
  }
   Serial.println('2');

}
void setMotor(int nSpeed, boolean bReverse)
{
  analogWrite(enablePin, nSpeed);
  digitalWrite(in1Pin, ! bReverse);
  digitalWrite(in2Pin, bReverse);
}

void stopMotor()
{
  analogWrite(enablePin, false);
}


