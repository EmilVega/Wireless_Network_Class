#include<SoftwareSerial.h> // 'set digital pins for serial communication'

SoftwareSerial wirelessNetworkYT(10, 11); // 'pin 10 as TX, pin 11 as RX'

char DAT = 0;    // 'variable to store received character'
int redLed = 2; // 'Yellow LED with digital pin number 5'
int greenLed = 3; // 'Green LED with digital pin number 4'
bool stateL = false;
int stateB = 0;
int stateM=0;
int button = 4;

void setup(){
  wirelessNetworkYT.begin(38400);// ' Serial communication between Arduino and the module at 38400 bps'
  pinMode(redLed,OUTPUT); // 'pin 3 as output'
  pinMode(greenLed,OUTPUT); // 'pin 6 as output'
  pinMode(button,INPUT);
  digitalWrite(redLed, LOW); // turn off red LED
  digitalWrite(greenLed, LOW); // turn off green LED
  Serial.begin(9600);
  Serial.print("Done");
}

void loop(){
  if (wirelessNetworkYT.available()){ // ' if there is information available from module'
    DAT = wirelessNetworkYT.read(); // 'stores in DAT the character received from module'
    if( DAT == '2' ){// ' if the character received is number 2'
      DAT=0;
      if (!stateL){
        stateL=true;
        digitalWrite(redLed, HIGH); // turn on red LED
        digitalWrite(greenLed, HIGH); // turn on green LED
      }else{
        stateL=false;
        digitalWrite(redLed, LOW); // turn off red LED
        digitalWrite(greenLed, LOW); // turn off green LED
      }
    }
  }
  stateB=digitalRead(button);
  if(stateB==HIGH){
        if(stateM==0){
            wirelessNetworkYT.write('2');
            stateM = 1 ;
        }
  }else {
      if (stateM == 1) {
          stateM = 0;
        }
    }
}
