#pragma once

#include "board.h"

#define NRF_TIMER0_BASE 0x40008000UL

#define TIMER_MODE REG32(NRF_TIMER0_BASE + 0x504)
#define TIMER_BITMODE REG32(NRF_TIMER0_BASE + 0x508)
#define TIMER_CC0 REG32(NRF_TIMER0_BASE + 0x540)
#define TIMER_PRESCALER REG32(NRF_TIMER0_BASE + 0x510)

#define TIMER_TASKS_START REG32(NRF_TIMER0_BASE + 0x000)
#define TIMER_TASKS_STOP REG32(NRF_TIMER0_BASE + 0x004)
#define TIMER_TASKS_CLEAR REG32(NRF_TIMER0_BASE + 0x00C)
#define TIMER_TASKS_CAPTURE0 REG32(NRF_TIMER0_BASE + 0x040)

void init_timer0(void);
void start_timer(void); // clear and start the timer
void stop_timer(void);  // stops and clears the timer
uint32_t read_ctr(void);
