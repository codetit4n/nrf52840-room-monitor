#include "twim.h"
#include "board.h"
#include "gpio.h"
#include "uarte.h"

void init_twim0(void) {
  // interrupts not needed in the project
  TWIM0_INTENCLR = 0xFFFFFFFF; // disable all interrupts
  // disable TWIM0 before configuring
  TWIM0_ENABLE = 0;
  // configure pins
  set_pin_input(I2C_SCL_PIN);
  // Fomrat: PIN[4:0] | PORT(bit5) | CONNECT(bit31: 0=connected, 1=disconnected)
  TWIM0_PSEL_SCL = (I2C_SCL_PIN << 0) // PIN
                   | (0 << 5)         // PORT
                   | (0 << 31);       // CONNECT = connected

  set_pin_input(I2C_SDA_PIN);
  TWIM0_PSEL_SDA = (I2C_SDA_PIN << 0) // PIN
                   | (0 << 5)         // PORT
                   | (0 << 31);       // CONNECT = connected

  // set frequency to 100kHz
  TWIM0_FREQUENCY = 0x01980000; // 100 kHz

  // clear RX and TX buffers
  TWIM0_RXD_PTR = 0;
  TWIM0_RXD_MAXCNT = 0;
  TWIM0_TXD_PTR = 0;
  TWIM0_TXD_MAXCNT = 0;

  // enable TWIM0
  TWIM0_ENABLE = 6;
}

int read_i2c(uint8_t addr, uint8_t *rx_buf, size_t rx_len) {

  if (rx_len == 0) {
    uarte_write("ERROR: read_i2c() length is 0\r\n",
                sizeof("ERROR: read_i2c() length is 0\r\n") - 1);
    return -1;
  }

  if (rx_buf == NULL) {
    uarte_write("ERROR: read_i2c() buffer is NULL\r\n",
                sizeof("ERROR: read_i2c() buffer is NULL\r\n") - 1);
    return -1;
  }

  TWIM0_ADDRESS = addr;
  TWIM0_RXD_PTR = 0;
  TWIM0_RXD_MAXCNT = 0;

  TWIM0_RXD_PTR = (uintptr_t)rx_buf;
  TWIM0_RXD_MAXCNT = rx_len;

  // tbd.

  return 0;
}
