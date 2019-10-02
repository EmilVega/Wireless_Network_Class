#include <SoftwareSerial.h> 

SoftwareSerial wirelessNetworkYT(10, 11);

char DAT = 0; 
int REDLED = 2; 
int BLUELED = 3;
int REDON=0;
int BLUEON=0;

void setup(){
  wirelessNetworkYT.begin(38400); 
  pinMode(REDLED, OUTPUT); 
  pinMode(BLUELED, OUTPUT); 
}

void loop(){
  if (wirelessNetworkYT.available()){ 
    DAT = wirelessNetworkYT.read(); 
    if ( DAT == '1' && REDON==0 ){ 
      digitalWrite (REDLED, HIGH); 
      REDON=1;
      delay(1000);
    } else {
      if ( DAT == '1' && REDON==1 ){ 
        digitalWrite (REDLED, LOW); 
        REDON=0;
        delay(1000);
      }
    }
    if( DAT == '2' && BLUEON==0 ){
      digitalWrite (BLUELED, HIGH); 
      BLUEON=1;
      delay(1000);
    } else {
      if ( DAT == '2' && BLUEON==1 ){ 
        digitalWrite (BLUELED, LOW); 
        BLUEON=0;
        delay(1000);
      }
    }
  }
}
