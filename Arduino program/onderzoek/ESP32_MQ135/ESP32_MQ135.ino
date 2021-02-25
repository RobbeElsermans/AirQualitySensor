void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("MQ-137: ");
  Serial.print(analogRead(35));
  Serial.println();
  delay(100);
}
