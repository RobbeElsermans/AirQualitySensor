#include <SDS011.h>
#include "Adafruit_CCS811.h"
#include "DHT.h"

// SDS011 (Luchtdeeltjes)
int rx2 = 16;
int tx2 = 17;
SDS011 my_sds;
float pm10;
float pm25;
int err;

// CCS811 (C02 & TVOC)
Adafruit_CCS811 ccs;

// MQ135  (CO2)
int mq135 = 35;

// MQ7    (CO)
int mq7 = 34;

// LM35   (°C)
int lm35 = 32;
double tempC = 0;

// DHT22  (°C & Humidity)
int dhtPin = 21;
int DHTTYPE = DHT22;
DHT dht(dhtPin, DHTTYPE);
float hum;
float temp;
float hic;

void setup() {
  my_sds.begin(rx2, tx2);
  dht.begin();
  Serial.begin(115200);
  // Wait for the sensor to be ready
  while(!ccs.available());
}

void loop() {
  Serial.print("MQ-137: ");
  Serial.print(analogRead(mq135));
  Serial.print("\t MQ-7: ");
  Serial.print(analogRead(mq7));
  Serial.println();

  // RawValue = analogRead(analogIn);
  // Voltage = (RawValue / 2048.0) * 3300; // 5000 to get millivots.
  // tempC = Voltage * 0.1;
  tempC = (analogRead(lm35) / 2048.0) * 330;
  Serial.print("LM35: ");
  Serial.print(tempC,1);
  Serial.println(" °C");

  hum = dht.readHumidity();
  temp = dht.readTemperature();
  hic = dht.computeHeatIndex(temp, hum, false);
  if (isnan(hum) || isnan(temp)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("% \t Temperature: ");
  Serial.print(temp);
  Serial.print("°C \t Heat index: ");
  Serial.print(hic);
  Serial.println("°C ");
  
  err = my_sds.read(&pm25, &pm10);
  if (!err) {
    Serial.print("PM2.5: " + String(pm25) + "\t");
    Serial.println("PM10:  " + String(pm10));
  }
  
  if(ccs.available()){
    if(!ccs.readData()){
      Serial.print("CO2: ");
      Serial.print(ccs.geteCO2());
      Serial.print("ppm, \t TVOC: ");
      Serial.print(ccs.getTVOC());
      Serial.print("ppb, \t Temp: ");
      Serial.println(ccs.calculateTemperature());
    }
    else{
      Serial.println("ERROR! CJCS811 Not Working");
      while(1);
    }
  }
  delay(1000);
}
