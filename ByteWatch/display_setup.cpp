#include "esp32-hal-spi.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include <Fonts/FreeSans12pt7b.h>

#include "pins.h"
#include "display_setup.h"
#include "bitmap_images.h"

String test_hours = "12";
String test_minutes = "00";
String test_seconds = "00";
String test_date = "01/02/03";

bool test_bluetooth_on = true;
bool test_bluetooth_connected = true;
uint16_t bluetooth_icon_color = 0x1104c2;

int test_wifi_amnt = 79;
bool test_wifi_on = true;

int test_sound_vol = 53;
bool test_sound_muted = false;

int test_battery_lvl = 37;
bool test_battery_charging = false;

Adafruit_SSD1351 tft = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, DIS_CS, DIS_DC, DIS_RST);

void clockDisplay() {
    clearDisplay();

    // Time
    tft.setTextColor(0x343C);
    tft.setTextColor(0x343C);
    tft.setTextWrap(false);
    tft.setFont(&FreeSans12pt7b);
    tft.setCursor(19, 59);
    tft.print(test_hours + ":" + test_minutes + ":" + test_seconds);

    // Bluetooth Status
    if(test_bluetooth_on){
      if(test_bluetooth_connected){
        tft.drawBitmap(22, 0, image_bluetooth_connected_bits, 14, 16, bluetooth_icon_color);
      } else {
        tft.drawBitmap(22, 0, image_bluetooth_on_bits, 14, 16, bluetooth_icon_color);
      }
    } else {
      tft.drawBitmap(22, 0, image_bluetooth_off_bits, 14, 15, 0x5AEC);
    }

    // WiFi Status
    if(test_wifi_on){
      if(test_wifi_amnt >= 21){
        if(test_wifi_amnt >= 41){
          if(test_wifi_amnt >= 61){
            if(test_wifi_amnt >=81){
              tft.drawBitmap(0, 0, image_wifi_4_bars_bits, 19, 15, 0xFFFF);
            } else tft.drawBitmap(0, 0, image_wifi_3_bars_bits, 19, 15, 0xFFFF);
          } else tft.drawBitmap(0, 0, image_wifi_2_bars_bits, 19, 15, 0xFFFF);
        } else tft.drawBitmap(0, 0, image_wifi_1_bars_bits, 19, 15, 0xFFFF);
      } else tft.drawBitmap(0, 0, image_wifi_nosig_bits, 19, 15, 0xFFFF);
    } else {
      tft.drawBitmap(0, 0, image_wifi_off_bits, 19, 15, 0x5AEC);
    }

    // volume_no_sound
    if(!test_sound_muted){
      if(test_sound_vol >= 1){
        if(test_sound_vol >= 41){
          if(test_sound_vol >= 81){
            tft.drawBitmap(82, 0, image_volume_loud_bits, 15, 15, 0xFFFF);
          } else tft.drawBitmap(82, 0, image_volume_normal_bits, 15, 15, 0xFFFF);
        } else tft.drawBitmap(82, 0, image_volume_low_bits, 15, 15, 0xFFFF);
      } else tft.drawBitmap(82, 0, image_volume_muted_bits, 15, 15, 0xFFFF);
    } else {
      tft.drawBitmap(82, 0, image_volume_no_sound_bits, 15, 15, 0x5AEC);
    }


    // battery_charging
    if (test_battery_charging) {
      tft.drawBitmap(103, 0, image_battery_charging_bits, 24, 15, 0xF685);
    } else {
      if (test_battery_lvl > 90) {
        tft.drawBitmap(103, 0, image_battery_100_bits, 24, 15, 0x5702);
      } else if (test_battery_lvl > 80) {
        tft.drawBitmap(103, 0, image_battery_80_bits, 24, 15, 0x5702);
      } else if (test_battery_lvl > 70) {
        tft.drawBitmap(103, 0, image_battery_70_bits, 24, 15, 0x5702);
      } else if (test_battery_lvl > 60) {
        tft.drawBitmap(103, 0, image_battery_60_bits, 24, 15, 0xFFFF);
      } else if (test_battery_lvl > 50) {
        tft.drawBitmap(103, 0, image_battery_50_bits, 24, 15, 0xFFFF);
      } else if (test_battery_lvl > 40) {
        tft.drawBitmap(103, 0, image_battery_40_bits, 24, 15, 0xFFFF);
      } else if (test_battery_lvl > 30) {
        tft.drawBitmap(103, 0, image_battery_30_bits, 24, 15, 0xFFFF);
      } else if (test_battery_lvl > 20) {
        tft.drawBitmap(103, 0, image_battery_20_bits, 24, 15, 0xc73200);
      } else if (test_battery_lvl > 10) {
        tft.drawBitmap(103, 0, image_battery_10_bits, 24, 15, 0xc73200);
      } else {
        tft.drawBitmap(103, 0, image_battery_0_bits, 24, 15, 0xb50c00);
      }
    }


    // message_mail
    tft.drawBitmap(109, 111, image_message_mail_bits, 17, 14, 0xFFFF);

    // menu_options
    tft.drawBitmap(2, 111, image_menu_options_bits, 14, 13, 0xFFFF);

    // Layer 10
    tft.setTextColor(0xFFFF);
    tft.setFont();
    tft.setCursor(47, 68);
    tft.print(test_date);

    // notification
    tft.drawBitmap(107, 109, image_notification_bits, 5, 5, 0xE0C4);

    // phone_call_incoming
    tft.drawBitmap(108, 20, image_phone_call_incoming_bits, 15, 15, 0x5702);
}

void clearDisplay(){
  tft.fillScreen(0x0000);
}