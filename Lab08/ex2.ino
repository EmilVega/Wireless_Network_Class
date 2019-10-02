// 'Declaration of global variables'
int tempC; // 'variable to hold temperature sensor value'
long tm,t,d; // 'variables to record time in seconds'
int pinLM35 = 0;
  
void setup()
{
  Serial.begin(38400);
  pinMode(pinLM35,INPUT);  // 'temperature sensor connected to analog 0'
  analogReference(INTERNAL);
}

void loop()
{
  tempC = analogRead(pinLM35); // 'analog reading temperature sensor values'
  tempC = (1.1 * tempC * 100.0)/1024.0;

  // 'required for converting time to seconds'
  tm = millis() ;
  t = tm/1000;
  d = tm%1000;

  Serial.flush () ;

  // 'printing time in seconds'
  Serial.print("time:") ;
  Serial.print(t) ;
  Serial.print(".") ;
  Serial.print(d);
  Serial.print("s\t");

  // 'printing temperature sensor values'
  Serial.print("temperature:");
  Serial.print(tempC);
  Serial.println ("C");
  delay(2000);  // 'delay of 2 seconds'
}
