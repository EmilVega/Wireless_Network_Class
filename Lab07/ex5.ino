#include <SoftwareSerial.h> 

SoftwareSerial wirelessNetworkYT(10, 11); 

char DAT = 0; 
int REDLED = 2; 
int BLUELED = 3;
int REDON=0;
int BLUEON=0;
int brightness=0;
int YELLOWLED=6;
int ORANGELED=5;
int GREENLED=4;
int YELLOWON=0;
int ORANGEON=0;
int GREENON=0;

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
      REDON=1;delay(1000);
    } else {
      if ( DAT == '1' && REDON==1 ){ 
        digitalWrite (REDLED, LOW);
        REDON=0;delay(1000);
      }
    } if ( DAT == '2' && BLUEON==0 ){ 
        digitalWrite (BLUELED, HIGH); 
        BLUEON=1;delay(1000);
    } else {
      if ( DAT == '2' && BLUEON==1 ){
        digitalWrite (BLUELED, LOW);
        BLUEON=0;delay(1000);
      }
    }
    if ( DAT == '3' && ORANGEON==0 ){ 
      digitalWrite (ORANGELED, HIGH); 
      ORANGEON=1;delay(1000);
    } else {
      if ( DAT == '3' && ORANGEON==1 ){ 
        digitalWrite (ORANGELED, LOW); 
        ORANGEON=0;delay(1000);
      }
    }
    if ( DAT == '4' && YELLOWON==0 ){ 
      digitalWrite (YELLOWLED, HIGH); 
      YELLOWON=1;delay(1000);
    } else {
      if ( DAT == '4' && YELLOWON==1 ){ 
        digitalWrite (YELLOWLED, LOW); 
        YELLOWON=0;delay(1000);
      }
    }
    if ( DAT == '5' && GREENON==0 ){ 
      digitalWrite (GREENLED, HIGH); 
      GREENON=1;delay(1000);
    } else { 
      if ( DAT == '5' && GREENON==1 ){
        digitalWrite (GREENLED, LOW); 
        GREENON=0;delay(1000);
      }
    }
    if ( DAT == '6'  ){ 
      digitalWrite (GREENLED, HIGH); 
      digitalWrite (YELLOWLED, HIGH);
      digitalWrite (REDLED, HIGH);
      digitalWrite (BLUELED, HIGH);
      digitalWrite (ORANGELED, HIGH);
      delay(1000);
    }
  }
}  
