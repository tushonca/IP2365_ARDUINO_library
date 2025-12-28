#pragma once
#include "IP2365.h"

IP2365::IP2365(){}
void IP2365::init(void){init(0x75);}
void IP2365::init(uint8_t address){
	_IP2365_ADDR = address;
	Wire.begin();
}

void IP2365::setCHRGState(uint8_t newState){
	_2rewriteRegister(0x00, newState, 0x01);
}
uint8_t IP2365::getCHRGState(void){
	return(_readRegister(0x00) & 0x01);
}
uint8_t IP2365::getCHRGType(void){
	uint8_t state = _readRegister(0x2B);
	if((state & 0x20) == 0x20){return(IP2365_END_CHRG);}
	return(state & 0x03);	
}

void IP2365::setOVPState(uint8_t newState){
	_2rewriteRegister(0x04, (newState << 1) , 0x02);
}
void IP2365::setOVPVoltage(uint8_t newState){
	_2rewriteRegister(0x04, (newState << 3), 0x18);
	
}
uint8_t IP2365::getOVPState(void){
	uint8_t state = _readRegister(0x22);
	return(state & 0x01);
}

void IP2365::setNTCHighT(uint8_t newState){
	_2rewriteRegister(0x05, (newState << 5), 0x60);
}
void IP2365::setNTCMidT(uint8_t newState){
	_2rewriteRegister(0x05, (newState << 3), 0x18);
}
void IP2365::setNTCLowT(uint8_t newState){
	_2rewriteRegister(0x05, (newState << 1), 0x06);
}

void IP2365::setNTCState(uint8_t newState){
	_2rewriteRegister(0x05, newState, 0x01);
}
uint8_t IP2365::getNTCState(void){
	uint8_t state = _readRegister(0x22);
	return((state & 0x38) >> 3);
}

void IP2365::setIBATType(uint8_t newState){
	_2rewriteRegister(0x0F, (newState << 3), 0x08);
}
void IP2365::setIBAT(uint16_t newCurrent){
	_2rewriteRegister(0x1F, newCurrent, 0x3F);
}
uint8_t IP2365::getIBAT(void){
	return(_readRegister(0x1F) & 0x3F);
}
void IP2365::setIVINType(uint8_t newState){
	_2rewriteRegister(0x0F, (newState << 2), 0x06);
	
}
void IP2365::setIVIN(uint16_t newCurrent){
	_2rewriteRegister(0x19, newCurrent, 0x3F);
}
uint8_t IP2365::getIVIN(void){
	return(_readRegister(0x19) & 0x3F);
}
	
void IP2365::setLEDOnCHRG(uint8_t newState){
	_2rewriteRegister(0x1A, (newState << 3), 0x18);
}
void IP2365::setLEDOnSTBY(uint8_t newState){
	_2rewriteRegister(0x1A, (newState << 1), 0x02);
}


void IP2365::_writeRegister(uint8_t regADDR, uint8_t data){
  Wire.beginTransmission(_IP2365_ADDR);
  Wire.write(regADDR);
  Wire.write(data);
  Wire.endTransmission();
}
uint8_t IP2365::_readRegister(uint8_t regADDR){
  Wire.beginTransmission(_IP2365_ADDR);
  Wire.write(regADDR);
  Wire.endTransmission();
  Wire.requestFrom(_IP2365_ADDR, uint8_t(0x01));
  return(Wire.read());
}
void IP2365::_2rewriteRegister(uint8_t regADDR, uint8_t data, uint8_t mask){
	uint8_t reg = _readRegister(regADDR);
	reg &= ~mask;
	reg |= (data & mask);
	_writeRegister(regADDR, reg);
}