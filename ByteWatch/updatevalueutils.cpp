#include "updatevalueutils.h"
#include "display_setup.h"

void updateBatteryValue(){
  while (true){
    test_battery_lvl--;
  }
}

void updateWifiValue(){
  while (true){
    test_wifi_amnt = random(100);
    Serial.print("Wifi signal: " + test_wifi_amnt);
  }
}