#include "eeprom.h"

extern I2C_HandleTypeDef hi2c1;

/* Write 1 byte to EEPROM */
void EEPROM_Write_Byte(uint16_t addr, uint8_t data)
{
    uint8_t buffer[2];

    buffer[0] = (uint8_t)(addr);  // memory address
    buffer[1] = data;             // data

    HAL_I2C_Master_Transmit(&hi2c1, EEPROM_ADDR, buffer, 2, 100);

    HAL_Delay(10);  // EEPROM write cycle delay (IMPORTANT)
}

/* Read 1 byte from EEPROM */
uint8_t EEPROM_Read_Byte(uint16_t addr)
{
    uint8_t data;
    uint8_t address = (uint8_t)(addr);

    HAL_I2C_Master_Transmit(&hi2c1, EEPROM_ADDR, &address, 1, 100);
    HAL_I2C_Master_Receive(&hi2c1, EEPROM_ADDR, &data, 1, 100);

    return data;
}
