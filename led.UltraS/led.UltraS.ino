//초음파 핀의 위치. VCC는 5V에, GND는 GND에 꽂는다.
int ulPin = D1;

//LED 핀의 위치. 다른 한쪽은 GND에 꽂는다. GND가 -극이다,
int led = D0;

//선언부, 아두이노의 동작이 시작되기 전, setup메소드가 먼저 실행된다.
void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop() {
  pinMode(ulPin,OUTPUT);
  
  delayMicroseconds(2);
  digitalWrite(ulPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ulPin, LOW);

  pinMode(ulPin,INPUT);
long duration = pulseIn(ulPin, HIGH);
  long cm = mtocm(duration);
  if(cm>100){
    digitalWrite(led, LOW);
    Serial.println("2.5m");
  }else{
    digitalWrite(led, HIGH);
  }
  delay(3 00);
  // put your main code here, to run repeatedly:
}

long mtocm(long a){
  return a/29/2;
}
