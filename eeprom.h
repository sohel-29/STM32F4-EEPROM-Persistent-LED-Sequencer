#ifndef EEPROM_H
#define EEPROM_H

#include "stm32f4xx_hal.h"

#define EEPROM_ADDR  (0x50 << 1)   // Change if A0/A1/A2 not GND

void EEPROM_Write_Byte(uint16_t addr, uint8_t data);
uint8_t EEPROM_Read_Byte(uint16_t addr);

#endif
