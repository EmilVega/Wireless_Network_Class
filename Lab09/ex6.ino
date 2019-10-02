#include <ESP8266WiFi.h>
#include <DHT.h>

//'Parameters WIFI'
const char* ssid = "iLuis";
const char* password = "12345678";
const char* host = "172.20.10.5"; //'localhost 􀀀IP from your PC'

// 'Sensor model'
#define DHTTYPE DHT11 //DHT21, DHT22

// 'Pin GPIO2'
#define DHTPIN 2 // GPIO2
DHT dht(DHTPIN, DHTTYPE, 27);

// 'Variables for Humidity and Temperature'
float temperature;
float humidity;

void setup(){
  Serial.begin(115200);
  Serial.println () ;
  dht.begin();
  Serial.printf ("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  } 
  Serial.println(" connected");
}

void loop()
{
  WiFiClient client;
  Serial.printf ("\n[Connecting to %s ... ", host);
  if ( client.connect(host, 80))
  {
    Serial.println("connected]");
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    Serial.println("[Sending a request]");
    client.print(String("GET /esp8266/?Temp=") + temperature + "&Hum=" + humidity + "HTTP/1.1\r\n" + "Host: " + host + "\r\n" +"Connection: close\r\n" +"\r\n") ;
    Serial.println("[Response:]");
    while (client.connected())
    {
      if ( client.available ())
      {
        String line = client .readStringUntil('\r\n');
        Serial.println( line ) ;
      }
    }
    client.stop() ;
    Serial.println("\n[Disconnected]");
  }
  else
  {
    Serial.println("connection failed !] ");
    client.stop() ;
  }
  delay(5000);
}
