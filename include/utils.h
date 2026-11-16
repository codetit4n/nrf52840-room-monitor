#pragma once

#include <stddef.h>
#include <stdint.h>

void *mem_cpy(void *dest, const void *src, size_t n);
uint8_t format_u32(uint32_t value, uint8_t *out);
void log_br(void);

#define MAX_DELAY_US 4294967
#define MAX_DELAY_S 4294

// capped at 4294967 us - for 32-bit timer, 4 prescaler
void delay_us(uint32_t us);

// capped at 4294.967 s - for 32-bit timer, 4 prescaler
void delay_s(uint32_t s);
