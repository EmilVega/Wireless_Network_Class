#include <IRremote.h>

#define Buzzer  3

// Define sensor pin
const int RECV_PIN = 4;
// Define IR Receiver and Results Objects

int pd=2; 
int led=6;
int ledIR=0;

int limit=850;

void setup(){
  // Serial Monitor @ 9600 baud
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(pd,OUTPUT);
  digitalWrite(Buzzer,LOW);
  digitalWrite(pd,HIGH); 
}

void loop(){
  Serial.println(analogRead(ledIR));
  int val = analogRead(ledIR);
  if (val<=limit){
    digitalWrite(Buzzer,HIGH);
    delay(20);
  }else if(val>limit){
    analogWrite(led,255);
    digitalWrite(Buzzer, LOW);
    delay(5000);
  }
}
