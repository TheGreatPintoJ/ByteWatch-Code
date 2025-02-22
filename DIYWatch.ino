#include "pins.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(CS);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(CS);
  delay(1000);
}
