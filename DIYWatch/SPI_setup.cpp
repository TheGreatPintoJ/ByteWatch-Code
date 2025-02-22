#include <SPI.h>
#include "SPI_setup.h"
#include "config.h"
#include "pins.h"

void spisetup(){
  SPI.begin(SCLK, MISO_pin, MOSI_pin, CS);
}