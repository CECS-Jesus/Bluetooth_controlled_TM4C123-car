
# Bluetooth Controlled Robot Car

## Introduction
Control a robot car using Bluetooth. This project leverages the HC-05 Bluetooth module and UART communication to receive commands from a device, such as a smartphone or PC, directing the car's movement.

## Table of Contents
- [Requirements](#requirements)
- [Setup & Configuration](#setup--configuration)
  - [Bluetooth Module](#bluetooth-module)
  - [Robot Car](#robot-car)
- [Usage](#usage)
- [Deliverables](#deliverables)
- [Contributing](#contributing)

## Requirements
- LaunchPad
- Robot car with two DC motors
- 6+ AA batteries
- HC-05 Bluetooth module
- Serial terminal application (e.g., tera term, Putty)
- Smartphone/Laptop with Bluetooth capability

## Setup & Configuration

### Bluetooth Module
- **Connection**: Connect the HC-05 Bluetooth module to the microcontroller using the provided pin configuration.
- **Configuration**: Use AT commands to set up the Bluetooth module. Ensure it's paired with your device.

### Robot Car
- Ensure the car is in data mode for communication.
- Configure the car to respond to specific Bluetooth commands.

## Usage
Use a Bluetooth terminal application to send commands:

- `F`: Move Forward (Green LED on)
- `B`: Reverse (Blue LED on)
- `L`: Turn Left (Yellow LED on)
- `R`: Turn Right (Purple LED on)
- `S`: Stop (All LEDs off)
- `U`: Increase Speed
- `D`: Decrease Speed

## Connection Configuration

<center>

|  HC-05 Bluetooth Module  | Launchpad         |
|:------------------------:|:-----------------:|
| State: Leave unconnected |                   |
| RX                       | UART1 Tx (PC5)    |
| TX                       | UART1 Rx (PC4)    |
| GND                      | GND               |
| VCC                      | VBUS              |
| EN1                      | 3.3v              |

---

</center>
