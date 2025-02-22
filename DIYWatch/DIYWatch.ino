#include "pins.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(SS);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(SPI_CLK);
  delay(1000);
}
