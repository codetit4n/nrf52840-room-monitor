# nrf52840-room-monitor

> [!WARNING]
> Work in progress!

A bare-metal room temperature and humidity monitor built with the nRF52840, SHT31 sensor, and an I²C LCD
display. Features handwritten peripheral drivers without relying on an SDK or HAL.

## Hardware

- [nRF52840 Development Kit](https://www.nordicsemi.com/Products/Development-hardware/nRF52840-DK)
- GY-SHT31-D temperature and humidity sensor
- 1602A LCD with I²C backpack

## Software

Bare-metal C, register-level TWIM (I²C) with EasyDMA, UARTE logging, and TIMER-based delays.

## Implementation

The nRF52840 communicates with the SHT31 sensor and LCD over a shared I²C bus. Temperature and relative
humidity are measured approximately every 10 seconds and displayed on the LCD.

The project focuses on learning I²C communication and implementing peripheral drivers directly using
hardware registers.

## Progress

Development milestones and implementation status are tracked in [PROGRESS.md](./PROGRESS.md).

### Commands

**Clean**

```sh
make clean
```

**Recover**

```sh
nrfutil device recover
```

**Flash**

```sh
nrfutil device program --firmware build/room-monitor.hex --options chip_erase_mode=ERASE_ALL,verify=VERIFY_READ,reset=RESET_SYSTEM
```

**UARTE Output**

```bash
minicom -D /dev/ttyACM0 -b 1000000
```
