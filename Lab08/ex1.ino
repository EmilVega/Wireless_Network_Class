// 'Declaration of global variables'
float tempC; // 'Variable to store the value obtained from the sensor (0 to 1023)'
int pinLM35 = 0; // 'Variable sensor input pin (A0)'

void setup () {
  // 'We change reference of the analog inputs'
  analogReference (INTERNAL);
  // 'We configure the serial port at 9600 bps'
  Serial.begin (9600);
}

void loop () {
  // 'With analogRead we read the sensor, remember that it is a value from 0 to 1023'
  tempC = analogRead (pinLM35);
  // 'We calculate the temperature with the formula'
  tempC = (1.1 * tempC * 100.0)/1024.0;
  // 'Send the data to the serial port'
  Serial.print (tempC);
  // 'Line break'
  Serial.print("\n");
  // 'We wait for a time to repeat the loop'
  delay (1000);
}
