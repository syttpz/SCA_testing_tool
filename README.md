# Side Channeling - Correlational power analysis


A simple, low-cost toolkit for side-channel power analysis on embedded systems using ESP32-C6 and STM32.

## Features

- Power trace capture during AES-128 encryption
- Trigger-based sampling using GPIO
- UART communication for plaintext exchange
- Correlation Power Analysis (CPA) in Python

## Hardware

- ESP32-C6 (XIAO)
- ADS7883 ADC
- INA333 amplifier
- STM32F103C8 (target)

## Usage

1. Flash STM32 with AES + trigger code
2. Flash ESP32 with SPI sampling + UART listener
3. Send plaintext over UART from STM32
4. Trigger and collect traces on ESP32
5. Run CPA script on collected data

## License

MIT License – for educational use only
