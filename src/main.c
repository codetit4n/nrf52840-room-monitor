#include "gpio.h"
#include "timer.h"
#include "twim.h"
#include "uarte.h"
#include "utils.h"

int main(void) {
  init_uarte0();
  init_twim0();
  init_timer0();

  while (1) {
    uarte_write("READY!\r\n", sizeof("READY!\r\n") - 1);
    delay_s(10);
  }
}
