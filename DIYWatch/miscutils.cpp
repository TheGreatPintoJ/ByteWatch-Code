#include <EEPROM.h>

void readStringFromEEPROM(String& buf, int baseaddress, int size) { //taken from the completeExample in the ESPUI library
	buf.reserve(size);
	for (int i = baseaddress; i < baseaddress+size; i++) {
		char c = EEPROM.read(i);
		buf += c;
		if(!c) break;
	}	
}