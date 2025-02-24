#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include <Fonts/FreeSans12pt7b.h>

#include "pins.h"


Adafruit_SSD1351 tft = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, DIS_CS, DIS_DC, DIS_RST);