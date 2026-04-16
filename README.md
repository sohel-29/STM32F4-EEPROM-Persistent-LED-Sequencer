# STM32F4-EEPROM-Persistent-LED-Sequencer
This project demonstrates LED sequence control with power‑loss memory using an STM32F4 microcontroller and an external I2C EEPROM.

6 LEDs are connected to PC0–PC3, PC10, PC11 and glow in a circular sequence. When the power is turned off and back on, the LEDs resume from the last glowing position by reading the current LED index stored in the EEPROM.

🔧 Features
6 LEDs (PC0–PC3, PC10–PC11) blinking in sequence.

External EEPROM (AT24C256, HW‑669 module) on I2C (PB8 = SCL, PB9 = SDA).

EEPROM persistence: Last LED index (0–5) is saved so the sequence continues from where it stopped after power‑cycle.

Write‑only‑when‑changed logic to reduce EEPROM wear‑out.

Simple, clean HAL‑based STM32F4 (STM32F446) implementation.

📐 Hardware Used
Microcontroller: STM32F446 (any STM32F4 Discovery / Nucleo board can be adapted).

LEDs: 6 LEDs on GPIOC pins:

LED 1 → PC0

LED 2 → PC1

LED 3 → PC2

LED 4 → PC3

LED 5 → PC10

LED 6 → PC11

EEPROM: HW‑669 module (AT24C256, 256‑kbit I2C EEPROM).

I2C pins: PB8 (SCL), PB9 (SDA) with 4.7 kΩ pull‑ups.

LEDs connected via current‑limiting resistors to GND (common‑anode not used).

 How It Works
At startup, the program reads the LED index from EEPROM address 0x0000.

The LEDs then glow in round‑robin sequence: LED0 → LED1 → ... → LED5 → LED0 → ....

Every time the LED index changes, the new value is written to the EEPROM only if it is different from the last‑written value.

On power‑off / power‑on, the MCU reads that saved index and resumes the LED sequence from the same position.

Build & Flash
IDE: STM32CubeIDE (or any HAL‑compatible IDE).

Build: make / “Build All”.

Flash: Use ST‑Link or similar debugger to flash the STM32F4 board.



