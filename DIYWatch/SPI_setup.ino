#include <SPI.h>

void spisetup(){
  SPI.begin(SCL, MISO, MOSI, 27);
}