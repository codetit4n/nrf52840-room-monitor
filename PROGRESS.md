# Progress

## 1. Project Setup

- [x] Set up bare-metal project with existing UARTE logger and TIMER driver
- [x] Connect SHT31 sensor and I²C LCD

## 2. TIMER-based Delays

- [x] Implement TIMER initialization and start/stop functions
- [x] Implement delay function using TIMER
- [x] Test TIMER delay blocking

## 3. I²C (TWIM) Driver

- [x] Implement TWIM initialization using registers and EasyDMA
- [ ] Implement blocking read/write operations
- [ ] Handle errors and timeouts
- [ ] Verify I²C communication

## 4. SHT31 Sensor

- [ ] Implement measurement commands and data reading
- [ ] Validate CRC and convert raw temperature/humidity values
- [ ] Verify readings over UART

## 5. LCD Display

- [ ] Identify I²C backpack controller and address
- [ ] Implement LCD initialization and text output
- [ ] Display temperature and humidity

## 6. Integration

- [ ] Handle sensor errors
- [ ] Test continuous operation
- [ ] Document wiring and add demo
