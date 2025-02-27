//#pragma once
#ifndef DISPLAY_SETUP_H
#define DISPLAY_SETUP_H

//Screen dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 128

//Hex colors
#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

extern String test_hours
extern String test_minutes;
extern String test_seconds;
extern String test_date;

extern bool test_bluetooth_on;
extern bool test_bluetooth_connected;
extern uint16_t bluetooth_icon_color;

extern int test_wifi_amnt;
extern bool test_wifi_on;

extern int test_sound_vol;
extern bool test_sound_muted;

extern int test_battery_lvl;
extern bool test_battery_charging;

void clockDisplay();
void clearDisplay();

#endif