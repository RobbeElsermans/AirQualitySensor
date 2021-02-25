// Example testing sketch for various DHT humidity/temperature sensors written by ladyada
// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

int dhtPin = 21;
int DHTTYPE = DHT22;
DHT dht(dhtPin, DHTTYPE);

void setup() {
  dht.begin();
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));
  delay(10);
}
void loop() {
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float hic = dht.computeHeatIndex(t, h, false);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("% \t Temperature: "));
  Serial.print(t);
  Serial.print(F("°C \t Heat index: "));
  Serial.print(hic);
  Serial.println(F("°C "));
}
