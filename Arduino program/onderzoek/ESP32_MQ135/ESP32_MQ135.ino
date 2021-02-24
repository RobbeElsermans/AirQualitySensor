#include <SDS011.h>

float p10,p25;
int error;

SDS011 my_sds;

void setup() {
  // put your setup code here, to run once:
  my_sds.begin(16,17);
  Serial.begin(9600);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("MQ-7: ");
  Serial.print(analogRead(34));
  Serial.print("          ");
  Serial.print("MQ-137: ");
  Serial.print(analogRead(35));
  Serial.println();

    error = my_sds.read(&p25,&p10);
  if (! error) {
    Serial.println("P2.5: "+String(p25));
    Serial.println("P10:  "+String(p10));
  }
  delay(100);
}
