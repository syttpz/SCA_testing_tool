# Side Channel Attack Project - Correlational power analysis


A low-cost setup using an ADC and an instrumentation amplifier to measure minimal power changes on an STM32 while it runs AES encryption. We analyze the traces in Python to visualize leakage and demonstrate simple key-recovery.

## Hardware

- XIAO-SEEED ESP32-C6
- ADS7883
- INA333
- STM32F103C8 (target)

# Wiring

![Screenshot](./screenshot.png)


## Features

- Power trace capture during AES-128 encryption
- Trigger-based sampling using GPIO
- UART communication for plaintext exchange
- Correlation Power Analysis (CPA) in Python


## Usage



