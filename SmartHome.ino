#include <IRremote.h> //library infrared

//deklarasi
int RECV_PIN = A1;
int led = 8;
int ONled;
int buzzer = 6;
int gas = 80;
int sensorgas = A0;

//kode yang ada ditombol remot
#define codestop 25245 //mendefinisikan code pada tombol stop

IRrecv irrecv(RECV_PIN); //pin infrared

decode_results results; //hasil decode

void setup()
{
Serial.begin(9600); // baud rate (bit persecond)
irrecv.enableIRIn(); //mulai receiver
pinMode(led, OUTPUT); // menjadikan led sebagai output
pinMode(buzzer, OUTPUT); // menjadikan buzzer sebagai output
pinMode(sensorgas, INPUT); // menjadikan MQ-5 sebagai input
}

void loop() {
if (irrecv.decode(&results)) { //hasil decode infrared
  unsigned int value = results.value;
  switch(value) {
    case codestop:
 if(ONled = 1) { // jika LED menyala
    digitalWrite(led, LOW); // akan mati jika tekan tombol stop
  }
  break;
  }
  irrecv.resume();
}

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
