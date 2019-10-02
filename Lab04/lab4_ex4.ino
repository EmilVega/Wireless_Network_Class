// Include IR Remote Library
#include <IRremote.h>
// Define sensor pin
const int RECV_PIN = 4;

// Define LED pin constants
const int redPin = 6;
const int yellowPin = 5;

// Define integer to remember toggle state
int togglestate = 0;
// Define IR Receiver and Results Objects

int brightness = 0; // how bright the LED is
int steps = 5;

IRrecv irrecv(RECV_PIN);
decode_results results ;

void setup(){
  irrecv.enableIRIn(); // Enable the IR Receiver  
  pinMode(yellowPin, OUTPUT); // Set LED pins as Outputs
  pinMode(redPin, OUTPUT);
}

void loop(){
  if ( irrecv.decode(&results)){
    switch(results.value){
      case 0x6BC6597B:
        togglestate=0;
        while(togglestate <3){
          analogWrite(redPin, brightness) ;
          brightness = brightness + steps;
          if (brightness == 0 || brightness == 255) {
            steps = -steps;
            togglestate++;
          }
          delay(30);
        }
        analogWrite(redPin,LOW);
        break;
      case 0x735B797E:
        togglestate=0;
        while(togglestate <3){
          analogWrite(yellowPin, brightness) ;
          brightness = brightness + steps;
          if (brightness == 0 || brightness == 255) {
            steps = -steps;
            togglestate++;
          }
          delay(30);
        }
        analogWrite(yellowPin,LOW);
        break;
    }  
    irrecv.resume();
  }
}
