#include <ESP8266WiFi.h>
#include <DHT.h>

// 'Sensor model'
#define DHTTYPE DHT11 //'DHT21, DHT22'

// 'Pin GPIO2'
#define DHTPIN 2 // GPIO2

DHT dht(DHTPIN, DHTTYPE, 27); // 'DHT11 works fine for ESP8266 threshold => MHZ CPU'

// 'Variables for Humidity and Temperature'
float temperature; // 'double'
float humidity;

void setup(){
  Serial.begin(115200);
  dht.begin();
}

void loop(){
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  Serial.println("------------------------");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C ");
  Serial.print("Humidity: ");
  Serial.print(humidity, 4);
  Serial.println("%");
  Serial.println("------------------------");
  Serial.println() ;
  delay(3000);
} // 'EOF loop()'
