#pragma once
#include <Arduino.h>
#include <Wire.h>

#define IP2365_START_CHRG 0x01
#define IP2365_STOP_CHRG 0x00
#define IP2365_TRICKLE_CHRG 0x00
#define IP2365_CC_CHRG 0x01
#define IP2365_CV_CHRG 0x03
#define IP2365_END_CHRG 0x04

#define IP2365_OVP_OFF 0x00
#define IP2365_OVP_ON 0x01
#define IP2365_OVP_3V0 0x00
#define IP2365_OVP_2V8 0x01
#define IP2365_OVP_2V6 0x02
#define IP2365_OVP_2V2 0x03
#define IP2365_OVP_DETECTED 0x01
#define IP2365_OVP_NOT_DETECTED 0x00

#define IP2365_NTC_ON 0x01
#define IP2365_NTC_OFF 0x00
#define IP2365_NTC_IN_HIGH_T 0x00
#define IP2365_NTC_IN_MID_T 0x04
#define IP2365_NTC_IN_NORMT 0x06
#define IP2365_NTC_IN_LOW_T 0x07

#define IP2365_NTC_LOW_T_1V52 0x00
#define IP2365_NTC_LOW_T_1V49 0x01
#define IP2365_NTC_LOW_T_1V44 0x02
#define IP2365_NTC_LOW_T_1V32 0x03
#define IP2365_NTC_MID_T_0V6  0x00
#define IP2365_NTC_MID_T_0V58 0x01
#define IP2365_NTC_MID_T_0V56 0x02
#define IP2365_NTC_MID_T_0V54 0x03
#define IP2365_NTC_HIGH_T_0V56 0x00
#define IP2365_NTC_HIGH_T_0V49 0x01
#define IP2365_NTC_HIGH_T_0V43 0x02
#define IP2365_NTC_HIGH_T_0V38 0x03

#define IP2365_IBAT_RSET 0x01
#define IP2365_IBAT_I2C 0x00

#define IP2365_IVIN_RSET
#define IP2365_IVIN_I2C

#define IP2365_LED_CHRG_OFF 0x00
#define IP2365_LED_CHRG_BLINK 0x10
#define IP2365_LED_CHRG_ON 0x11

#define IP2365_LED_STBY_OFF 0x00
#define IP2365_LED_STBY_ON 0x01



class IP2365 {
  public:
    IP2365();
    void init(void);
	void init(uint8_t address);
    void setCHRGState(uint8_t newState);
    uint8_t getCHRGState(void);
	uint8_t getCHRGType(void);
	
	void setOVPState(uint8_t newState);
    void setOVPVoltage(uint8_t newState);
    uint8_t getOVPState(void);
	
    void setNTCHighT(uint8_t newState);
    void setNTCMidT(uint8_t newState);
    void setNTCLowT(uint8_t newState);
    void setNTCState(uint8_t newState);
    uint8_t getNTCState(void);
	
    void setIBATType(uint8_t newState);
    void setIBAT(uint16_t newCurrent);
    uint8_t getIBAT(void);
    void setIVINType(uint8_t newState);
    void setIVIN(uint16_t newCurrent);
    uint8_t getIVIN(void);
	
    void setLEDOnCHRG(uint8_t newState);
	void setLEDOnSTBY(uint8_t newState);

  private:
  	void _2rewriteRegister(uint8_t regADDR, uint8_t data, uint8_t mask);
    void _writeRegister(uint8_t regADDR, uint8_t data);
    uint8_t _readRegister(uint8_t regADDR);
    uint8_t _IP2365_ADDR = 0x75;
    
};

/* 
 * IP2365 Default registers values:
 * 0x00 - 0xB1
 * 0x04 - 0x6B
 * 0x05 - 0x8B
 * 0x0F - 0x0E
 * 0x19 - 0x89
 * 0x1F - 0x09
 * 0x1A - 0x22
 * 0x2B - 0x13
 * 0x22 - 0x60
 */
