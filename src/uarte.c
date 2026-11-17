#include "uarte.h"
#include "gpio.h"

static uint8_t tx_buf[UART_TX_BUF_SIZE];

static void tx_send_blocking(const uint8_t *tx, size_t len) {
  if (len == 0)
    return;
  if (len > 0xFFFF)
    len = 0xFFFF; // MAXCNT is 16-bit

  UARTE0_EVENTS_ENDTX = 0;
  // Set up TX buffer
  UARTE0_TXD_PTR = (uint32_t)(uintptr_t)tx;
  UARTE0_TXD_MAXCNT = len;

  // Start TX
  UARTE0_TASKS_STARTTX = 1;
  // Wait for TX to complete - blocking
  while (UARTE0_EVENTS_ENDTX == 0) {
  }
}

void init_uarte0(void) {
  UARTE0_ENABLE = 0; // Disable UARTE while configuring

  P0_CNF(TX_PIN) =
      (1 << 0) | // DIR = Output
      (1 << 1) | // INPUT disconnect (input buffer not needed for TX)
      (0 << 2) | // PULL = none (field)
      (0 << 8) | // DRIVE = standard (field)
      (0 << 16); // SENSE = disabled

  // PSEL format: PIN[4:0] | PORT(bit5) | CONNECT(bit31: 0=connected,
  // 1=disconnected)
  UARTE0_PSEL_TXD = (TX_PIN << 0) | (0 << 5) | (0 << 31);

  UARTE0_PSEL_RXD = (1 << 31); // RX disconnected (TX-only)

  UARTE0_CONFIG = (0 << 0) |   // HWFC disabled
                  (0x0 << 1) | // PARITY excluded
                  (0 << 4);    // 1 stop bit

  UARTE0_BAUDRATE = 0x10000000; // 1Mega baud (per datasheet table)

  UARTE0_EVENTS_ENDTX = 0;
  UARTE0_EVENTS_TXSTOPPED = 0;

  UARTE0_ENABLE = 8; // Enable UARTE
}

void uarte_write(const char *text, size_t len) {
  if (len > sizeof(tx_buf))
    len = sizeof(tx_buf);

  for (size_t i = 0; i < len; i++)
    tx_buf[i] = (uint8_t)text[i];

  tx_send_blocking(tx_buf, len);
}
