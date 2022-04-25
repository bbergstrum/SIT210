#include "Adafruit_DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT11

int temp_reading;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
}

void loop() {
  temp_reading = dht.getTempCelcius();
  Particle.publish("temperature", String(temp_reading), PRIVATE);
  delay(1000);
}
