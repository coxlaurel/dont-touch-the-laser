# don't touch the laser
**Laurel Cox and Daniel Theunissen**

Embedded Software fall 2026 midterm project

## Project Overview
This is the firmware for a laser beam-break detector.

## Hardware Architecture
The basic concept here is similar to that of an IR receiver. A red 5mW laser diode is aimed at a piece of retroreflective tape on the opposite wall. The light is reflected and sensed by a photodiode, which goes into a transimpedance amplifier (TIA). This allows any interference in the reflection to be sensed as a change in voltage. Then, we use a 12-bit ADC with a SPI interface to sample the value. However, this signal is really small (on the order of 50-100nA or 2-4 LSBs), so to sense it, we modulate the LED signal. Then, in firmware, we apply lock-in detection to demodulate the TIA output and determine if the LED signal is present or not.

<img src="assets/laser_hardware.png" width="50%" alt="hardware">

### TIA Design
<img src="assets/tia_schematic.png" width="25%" alt="tia">

## Firmware Architecture
<img src="assets/firmware_architecture.png" width="50%" alt="firmware">
