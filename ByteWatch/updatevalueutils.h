#ifndef UPDATEVALUEUTILS_H
#define UPDATEVALUEUTILS_H

TaskHandle_t updateBatteryTask, updateWifiTask;

void updateBatteryValue(void *parameter);
void updateWifiValue(void *parameter);

#endif