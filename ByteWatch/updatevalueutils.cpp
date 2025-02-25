#include "updatevalueutils.h"
//#include "display_setup.h"

void updateBatteryValue(void *parameter){
  while (true){
    test_battery_lvl--;
    vTaskDelay(pdMS_TO_TICKS(10000)); // 10 second delay
  }
}

void updateWifiValue(void *parameter){
  while (true){
    test_wifi_amnt = random(100);
    Serial.print("Wifi signal: " + test_wifi_amnt);
    vTaskDelay(pdMS_TO_TICKS(500)); // half-second delay
  }
}