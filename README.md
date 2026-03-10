# ESP32 Bluetooth Mouse Emulator 🖱️

A hardware-level project that transforms an ESP32 microcontroller into a fully functional, wireless Bluetooth Low Energy (BLE) mouse. This embedded system processes physical hardware inputs and translates them into seamless, low-latency cursor controls compatible with modern Bluetooth-enabled devices.

## ✨ Features
* **BLE Connectivity:** Utilizes the ESP32's built-in Bluetooth Low Energy capabilities for energy-efficient, wireless communication.
* **Low-Latency Input:** Optimized C++ processing ensures real-time cursor movement and click translation without noticeable lag.
* **Plug-and-Play Compatibility:** Recognized natively as a standard Human Interface Device (HID) by operating systems (Windows, macOS, Linux, Android) without the need for custom drivers.

## 🛠️ Tech Stack
* **Microcontroller:** ESP32
* **Language:** C++
* **Domain:** Embedded Systems, BLE Communication, HID Devices

## 🚀 Getting Started

### Prerequisites
* An ESP32 development board.
* Arduino IDE or PlatformIO installed on your machine.
* The ESP32 board manager installed in your IDE.
* The `ESP32-BLE-Mouse` library (if utilized in the source).

### Installation & Flashing
1. Clone this repository:
   ```bash
   git clone [https://github.com/Codered1729/ESP32_BLMouse.git](https://github.com/Codered1729/ESP32_BLMouse.git)
