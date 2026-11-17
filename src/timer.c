#include "timer.h"

void init_timer0(void) {
  TIMER_MODE = 0;    // timer mode
  TIMER_BITMODE = 3; // 32-bit
  TIMER_PRESCALER = 4;
}

void start_timer(void) {
  // reset timer to 0
  TIMER_TASKS_CLEAR = 1;

  // start timer
  TIMER_TASKS_START = 1;
}

void stop_timer(void) { TIMER_TASKS_STOP = 1; }

uint32_t read_ctr(void) {
  TIMER_TASKS_CAPTURE0 = 1;
  return TIMER_CC0;
}
