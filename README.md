# ESP32 Temperature-Controlled Fan

An embedded systems project that uses an ESP32 to monitor ambient temperature and automatically control a DC fan.

Overview

This project uses a DHT11 temperature sensor to measure ambient temperature. When the temperature reaches a predefined threshold, the ESP32 activates a DC motor through an L293D motor driver. An OLED display shows the measured temperature and whether the fan is ON or OFF.

## Components

ESP32(or arduino uno but you would have to change some parts),DHT11 temperature and humidity senso,DC motor,L293D motor driver,0.97-inch I2C OLED display,breadboard and jumper wires

and a suitable power supply for the motor
## Compatibility

This project was developed for the ESP32 WROOM 32
adapting it for an Arduino Uno would require modifications
to the code and pin assignments to account for hardware differences.

## i will add an image of the wiring diagram later
