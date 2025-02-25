#include <Arduino.h>

#include "pins.h"
#include "wifi_functs.h"
#include "config.h"
#include "miscutils.h"
//#include "display_setup.h"
#include "updatevalueutils.h"

void setup(){
  Serial.begin(9600);
  xTaskCreatePinnedToCore(updateBatteryValue, "Update Battery Value", 2048, NULL, 1, &updateBatteryTask, 0);
  xTaskCreatePinnedToCore(updateWifiValue, "Update Wifi Signal", 2048, NULL, 1, &updateWifiTask, 1);
}

void loop(){}
