// Include IR Remote Library
#include <IRremote.h>
// Define sensor pin
const int RECV_PIN = 4;
// Define LED pin constants
const int redPin = 10;
const int yellowPin = 11;
// Define integer to remember toggle state
int togglestate = 0;
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results ;
void setup(){
irrecv.enableIRIn(); // Enable the IR Receiver
pinMode(yellowPin, OUTPUT); // Set LED pins as Outputs
pinMode(redPin, OUTPUT);
}
void loop(){
if ( irrecv.decode(&results)){
switch( results .value){
case 0x6BC6597B: //Update value one according to your readings
digitalWrite (redPin, HIGH);// Turn on LED for 2 Seconds
delay(2000);
digitalWrite (redPin, LOW);
break;
case 0x735B797E: //Update value one according to your readings
// Toggle LED On or Off
if ( togglestate ==0){
digitalWrite (yellowPin, HIGH);
togglestate =1;
}
else {
digitalWrite (yellowPin, LOW);
togglestate =0;
}
break;
}
irrecv .resume();
}
}
