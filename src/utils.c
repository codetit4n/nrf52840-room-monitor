#include "utils.h"
#include "timer.h"
#include "uarte.h"

void *mem_cpy(void *dest, const void *src, size_t n) {
  uint8_t *d = (uint8_t *)dest;
  const uint8_t *s = (const uint8_t *)src;

  while (n--) {
    *d++ = *s++;
  }

  return dest;
}

uint8_t format_u32(uint32_t value, uint8_t *out) {

  uint8_t tmp[10];
  uint8_t n = 0;
  uint8_t pos = 0;

  if (out == NULL)
    return 0;

  if (value == 0) {
    out[0] = (uint8_t)'0';
    return 1;
  }

  while (value != 0 && n < sizeof(tmp)) {
    uint32_t digit = value % 10u;
    tmp[n++] = (uint8_t)('0' + digit);
    value /= 10u;
  }

  for (uint8_t i = 0; i < n; i++) {
    out[pos + i] = tmp[n - 1 - i];
  }

  return pos + n;
}

void log_br(void) {
  uint8_t line[2];

  line[0] = '\r';
  line[1] = '\n';

  uarte_write((const char *)line, 2);
}

void delay_us(uint32_t us) {
  // clamped to MAX_DELAY_US
  if (us > MAX_DELAY_US) {
    us = MAX_DELAY_US;
    uarte_write(
        "WARNING: delay_us() can't be more than 4294967 us (4.294967 s)\r\n",
        sizeof("WARNING: delay_us() can't be more than 4294967 us (4.294967 "
               "s)\r\n") -
            1);
  }

  start_timer();
  uint32_t ctr = 0;
  do {
    ctr = read_ctr();
  } while (ctr < us);
  stop_timer();
}

void delay_s(uint32_t s) {
  // clamped to MAX_DELAY_S
  if (s > MAX_DELAY_S) {
    s = MAX_DELAY_S;
    uarte_write(
        "WARNING: delay_s() can't be more than 4294 s (~71 min)\r\n",
        sizeof("WARNING: delay_s() can't be more than 4294 s (~71 min)\r\n") -
            1);
  }

  start_timer();
  uint32_t ctr = 0;
  do {
    ctr = read_ctr();
  } while (ctr < s * 1000000);
  stop_timer();
}
