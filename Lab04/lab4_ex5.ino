// Include IR Remote Library
#include <IRremote.h>
// Define sensor pin
const int RECV_PIN = 4;
// Define LED pin constants

const int redPin = 6;
const int greenPin = 5;
const int bluePin = 9;

// Define integer to remember toggle state
int togglestate = 0;
// Define IR Receiver and Results Objects

int brightness = 0; // how bright the LED is
int steps = 5;

IRrecv irrecv(RECV_PIN);
decode_results results ;

void setup(){
  irrecv.enableIRIn(); // Enable the IR Receiver
  pinMode(greenPin, OUTPUT); // Set LED pins as Outputs
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  analogWrite(greenPin,255);
  analogWrite(bluePin,255);
  analogWrite(redPin, 255) ;
}

void loop(){
  if (irrecv.decode(&results)){
    switch(results.value){
      case 0x1EC81DBF:
        togglestate=0;
        while(togglestate <3){
          analogWrite(greenPin,255);
          analogWrite(bluePin,255);
          analogWrite(redPin, brightness) ;
          brightness = brightness + steps;
          if (brightness == 0 || brightness == 255) {
            steps = -steps;
            togglestate++;
          }
          delay(30);
        }
        analogWrite(redPin,255);
        break;
      case 0x450753D6:
        togglestate=0;
        while(togglestate <3){
          analogWrite(bluePin,255);
          analogWrite(redPin,255);
          analogWrite(greenPin, brightness) ;
          brightness = brightness + steps;
          if (brightness == 0 || brightness == 255) {
            steps = -steps;
            togglestate++;
          }
          delay(30);
        }
        analogWrite(greenPin,255);
        break;
      case 0xBA0F4EDF:
        togglestate=0;
        while(togglestate <3){
          analogWrite(redPin,255);
          analogWrite(greenPin,255);
          analogWrite(bluePin, brightness) ;
          brightness = brightness + steps;
          if (brightness == 0 || brightness == 255) {
            steps = -steps;
            togglestate++;
          }
          delay(30);
        }
        analogWrite(bluePin,255);
        break;
    }
    irrecv.resume();
  }
}
