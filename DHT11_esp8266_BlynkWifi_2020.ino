#include <Wire.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include "DHTesp.h"
#define BLYNK_PRINT Serial
#define DHTTYPE DHT11
DHTesp dht;

//Your auth Token from Blynk
char auth[] = "Your Token"; 

char ssid[] = "Wifi Name";
char pass[] = "Wifi Password";

void setup() {
  Blynk.begin(auth, ssid, pass);
  dht.setup(12, DHTesp::DHT11);
  Serial.begin(9600);
 
}
void loop() {
  delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  delay(2000);
}
