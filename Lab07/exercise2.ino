#include <SoftwareSerial.h> // 'set digital pins for serial communication'

SoftwareSerial wirelessNetworkYT(10, 11); // 'pin 10 as RX, pin 11 as TX'

char DAT = 0;   // 'variable to store received character'
int REDLED = 2; // 'Red LED to digital pin number 2'
int BLUELED = 3; // 'Green LED with digital pin number 3'

void setup(){
  wirelessNetworkYT.begin(38400); // 'Serial communication between Arduino and the module at 38400 bps'
  pinMode(REDLED, OUTPUT);  // 'pin 2 as output'
  pinMode(BLUELED, OUTPUT); // 'pin 3 as output'
}

void loop(){
  if (wirelessNetworkYT.available()){   // 'if there is information available from module'
    DAT = wirelessNetworkYT.read();     // 'stores in DATO the character received from module'
    if ( DAT == '1' )   // 'if the character received is number 1'
      digitalWrite (REDLED, HIGH);  // turn on red LED
    if ( DAT == '2' )   // 'if the character received is number 2'
      digitalWrite (REDLED, LOW); // turn off red LED
    if ( DAT == '3' )   // 'if the character received is number 3'
      digitalWrite (BLUELED, HIGH); // turn on green LED
    if ( DAT == '4' )   // 'if the character received is number 4'
      digitalWrite (BLUELED, LOW); // turn off green LED
  }
}
