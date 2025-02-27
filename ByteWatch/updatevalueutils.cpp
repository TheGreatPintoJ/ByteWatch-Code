#include <Arduino.h>

#include "updatevalueutils.h"
#include "display_setup.h"

void updateBatteryValue(){
  while (true){
    updateWifiValue();
  }
}

void updateWifiValue(){
  test_wifi_amnt = random(100);
  Serial.print("Wifi signal: " + test_wifi_amnt);
}