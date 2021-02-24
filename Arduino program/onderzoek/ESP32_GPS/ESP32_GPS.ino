//Change the code below by your sketch
//Code for Gps
#include <TinyGPS++.h>
#include <HardwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 115200;

// The TinyGPS++ object
TinyGPSPlus gps;

#include "HardwareSerial.h"
HardwareSerial gps_serial(2);

#define RXD2 26
#define TXD2 25

void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(115200);

  gps_serial.begin(9600, SERIAL_8N1, RXD2, TXD2);

  Serial.println("Serial Txd is on pin: " + String(TX));
  Serial.println("Serial Rxd is on pin: " + String(RX));
}

void loop() {
  while (gps_serial.available()) {
    //Serial.print(char(gps_serial.read()));  // read from gps, write to serial debug port
    gps.encode(gps_serial.read());

    if (gps.location.isUpdated())
    {
      Serial.print("LAT="); Serial.print(gps.location.lat(), 6);
      Serial.print("LNG="); Serial.println(gps.location.lng(), 6);
    }
  }

  //Serial.print("LAT=");  Serial.println(gps.location.lat(), 6);
  //Serial.print("LONG="); Serial.println(gps.location.lng(), 6);
  //Serial.print("ALT=");  Serial.println(gps.altitude.meters());
}
