int inByte ; // S t o r e s incoming command
void setup () {
  Serial.begin(9600);
  pinMode (13, OUTPUT); // LED p i n
  Serial.println ("Ready") ; // Ready t o r e c e i v e commands
}
void loop () {
  if (Serial.available() > 0 ) { // A byte i s ready t o r e c e i v e
    inByte = Serial.read () ;  
    if (inByte == '0' ) { // byte i s ’ o ’
      digitalWrite (13,HIGH);
      Serial.println ( "LED is ON" ) ;
      delay(2000);
    }
    else
    {
      // byte i s n ’ t ’ o ’
      digitalWrite (13, LOW) ;
      Serial.println ( "LED is OFF" ) ;
    }
  }
}
