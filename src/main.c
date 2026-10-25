#include "board.h"
#include "gpio.h"
#include "timer.h"
#include "uarte.h"

int main(void) {
  init_uarte0();
  // init_timer0();

  while (1) {
    uarte_write("READY!\r\n", sizeof("READY!\r\n") - 1);
    delay(1000);
  }
}
