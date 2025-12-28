#include <IP2365_2.h>
IP2365 IP;
void setup() {
  IP.init();
  Serial.begin(115200);
  Serial.setTimeout(100);
}

void loop() {
  if(Serial.available()){
    int8_t com = Serial.read();
    if(com == '?'){Serial.print(F(">   ?: help page (you are here)\n    1: set charge state [1 - on, 0 - off]\n    2: set charge current [0 - 3000mA]\n    3: set charge currnet setting type [0 - I2C, 1 - I2C*(R/R)]\n    4: get charge status {0x00 - TRICKLE_CHRG, 0x01 - CC_CHRG, 0x03 - CV_CHRG, 0x04 - END_CHRG}\n    5: set max input current [0 - 3000mA]\n    6: set input currnet setting type [0 - I2C, 1 - I2C*(R/R)]\n    7: set LED light on charge [0 - LED_CHRG_OFF, 2 - LED_CHRG_BLINK, 3 - LED_CHRG_ON]\n    8: set LED light on standby [0 - LED_STBY_OFF, 1 - LED_STBY_ON]\n"));}
    if(com == '1'){Serial.print(F("\n>   write new charge state [1 - on, 0 - off]\n    ")); while(Serial.available() == 0){} uint8_t newCHRGState = Serial.parseInt(); IP.setCHRGState(newCHRGState); Serial.print(newCHRGState); Serial.print(F("\n>"));}
    if(com == '2'){Serial.print(F("\n>   write new charge current [0 - 3000mA]\n    ")); while(Serial.available() == 0){} uint16_t newCHRGCurrent = Serial.parseInt(); IP.setIBAT(newCHRGCurrent); Serial.print(newCHRGCurrent); Serial.print(F("\n>"));}
    if(com == '3'){Serial.print(F("\n>   write new charge setting currunt method [0 - I2C, 1 - I2C*(R/R)]\n   ")); while(Serial.available() == 0){} uint8_t newCHRGCurrentType = Serial.parseInt(); IP.setIBATType(newCHRGCurrentType); Serial.print(newCHRGCurrentType); Serial.print(F("\n>"));}
    if(com == '4'){Serial.print(F("\n>   get charge status {0x00 - TRICKLE_CHRG, 0x01 - CC_CHRG, 0x03 - CV_CHRG, 0x04 - END_CHRG}\n   ")); Serial.print(IP.getCHRGType(), HEX); Serial.print(F("\n>"));}
    if(com == '5'){Serial.print(F("\n>   set max input current [0 - 3000mA]\n   ")); while(Serial.available() == 0){} uint8_t newVINCurrent = Serial.parseInt(); IP.setIVIN(newVINCurrent); Serial.print(newVINCurrent); Serial.print(F("\n>"));}
    if(com == '6'){Serial.print(F("\n>   set input currnet setting type [0 - I2C, 1 - I2C*(R/R)]\n   ")); while(Serial.available() == 0){} uint8_t newVINCurrentType = Serial.parseInt(); IP.setIVINType(newVINCurrentType); Serial.print(newVINCurrentType); Serial.print(F("\n>"));}
    if(com == '7'){Serial.print(F("\n>   set LED light on charge [0 - LED_CHRG_OFF, 2 - LED_CHRG_BLINK, 3 - LED_CHRG_ON]\n   ")); while(Serial.available() == 0){} uint8_t newLEDCHRGState = Serial.parseInt(); IP.setLEDOnCHRG(newLEDCHRGState); Serial.print(newLEDCHRGState); Serial.print(F("\n>"));}
    if(com == '8'){Serial.print(F("\n>   set LED light on standby [0 - LED_STBY_OFF, 1 - LED_STBY_ON]\n   ")); while(Serial.available() == 0){} uint8_t newLEDSTBYState = Serial.parseInt(); IP.setLEDOnSTBY(newLEDSTBYState); Serial.print(newLEDSTBYState); Serial.print(F("\n>"));}
  }
}
