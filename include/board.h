#pragma once

#define BOARD_NAME "nRF52840-DK"

#include <stddef.h>
#include <stdint.h>

#define REG32(addr) (*(volatile uint32_t *)(addr))

#define I2C_SCL_PIN 26 // P0.26
#define I2C_SDA_PIN 27 // P0.27

#define I2C_SHT31_ADDRESS 0x44 // SHT31 sensor I2C address
#define I2C_LCD_ADDRESS 0x20   // LCD I2C address
