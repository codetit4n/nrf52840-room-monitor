# Progress

## 1. Project Setup

- [ ] Set up bare-metal project with existing UARTE logger and TIMER driver
- [ ] Connect SHT31 sensor and I²C LCD

## 2. I²C (TWIM) Driver

- [ ] Implement TWIM initialization using registers and EasyDMA
- [ ] Implement blocking read/write operations
- [ ] Handle errors and timeouts
- [ ] Verify I²C communication

## 3. SHT31 Sensor

- [ ] Implement measurement commands and data reading
- [ ] Validate CRC and convert raw temperature/humidity values
- [ ] Verify readings over UART

## 4. LCD Display

- [ ] Identify I²C backpack controller and address
- [ ] Implement LCD initialization and text output
- [ ] Display temperature and humidity

## 5. Integration

- [ ] Update readings every 10 seconds using TIMER
- [ ] Handle sensor errors
- [ ] Test continuous operation
- [ ] Document wiring and add demo
