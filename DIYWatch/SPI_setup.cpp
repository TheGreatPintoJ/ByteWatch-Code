#include <SPI.h>
#include "SPI_setup.h"
#include "config.h"
#include "pins.h"

void spisetup(){
  SPI.begin(SPI_CLK, SPI_MISO, SPI_MOSI, SS);
}