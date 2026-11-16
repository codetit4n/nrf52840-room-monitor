#include "twim.h"
#include "board.h"
#include "gpio.h"

void init_twim0(void) {
  // interrupts not needed in the project
  TWIM0_INTENCLR_REG = 0xFFFFFFFF; // disable all interrupts
  // disable twim
  TWIM0_ENABLE_REG = 0;
  // configure pins
  set_pin_input(SCL_PIN);
  // Fomrat: PIN[4:0] | PORT(bit5) | CONNECT(bit31: 0=connected, 1=disconnected)
  TWIM0_PSEL_SCL_REG = (SCL_PIN << 0) // PIN
                       | (0 << 5)     // PORT
                       | (0 << 31);   // CONNECT = connected

  set_pin_input(SDA_PIN);
  TWIM0_PSEL_SDA_REG = (SDA_PIN << 0) // PIN
                       | (0 << 5)     // PORT
                       | (0 << 31);   // CONNECT = connected

  // set frequency to 100kHz
  TWIM0_FREQUENCY_REG = 0x01980000; // 100 kHz

  // clear RX and TX buffers
  TWIM0_RXD_PTR_REG = 0;
  TWIM0_RXD_MAXCNT_REG = 0;
  TWIM0_TXD_PTR_REG = 0;
  TWIM0_TXD_MAXCNT_REG = 0;

  // enable twim
  TWIM0_ENABLE_REG = 6;
}
