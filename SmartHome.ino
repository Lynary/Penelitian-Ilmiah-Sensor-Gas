#include <IRremote.h> //library infrared

//deklarasi
int led = 8;
int buzzer = 10;
int gas = 80;
int sensorgas = A0;

void setup()
{
Serial.begin(9600); // baud rate (bit persecond)
pinMode(led, OUTPUT); // menjadikan led sebagai output
pinMode(buzzer, OUTPUT); // menjadikan buzzer sebagai output
pinMode(sensorgas, INPUT); // menjadikan MQ-2 sebagai input
}

void loop() {
// sensor gas
int analogsensor = analogRead(sensorgas);
Serial.println(analogsensor);
if (analogsensor > gas){
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
}else{
  digitalWrite(buzzer,LOW);
  digitalWrite(led,LOW);
} 
}
