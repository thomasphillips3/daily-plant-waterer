# 🌿 Arduino Plant Watering System

This project is an automatic plant watering system powered by an Arduino Uno. It waters your plant once every 24 hours using an IoT power relay and displays a countdown to the next watering on an I²C 16x2 LCD.

Perfect for beginner makers, weekend tinkerers, and parents introducing their kids to electronics and code!

---

## 🧠 Features

- Waters your plant **once per day** for **20 seconds**
- Uses a **relay-controlled pump**
- Shows a **countdown timer** to the next watering on an LCD screen
- Sends helpful info to the **Serial Monitor** at startup
- Teachable and tweakable for kids and beginners

---

## 🧰 Hardware Required

| Item                      | Description |
|---------------------------|-------------|
| Arduino Uno               | Main microcontroller |
| I²C 16x2 LCD Display      | For countdown display |
| IoT Power Relay (DLI)     | Controls the power to your pump |
| Submersible pump          | Waters your plant |
| Jumper wires              | For connections |
| Breadboard (optional)     | For prototyping |
| 5V power (USB or adapter) | To power the Arduino |

---

## 🔌 Wiring Guide

### 🖥️ I²C LCD (Funduino backpack)
| LCD Pin | Arduino Pin |
|---------|-------------|
| GND     | GND         |
| VCC     | 5V          |
| SDA     | A4          |
| SCL     | A5          |

📍 Default I²C address: `0x27`  
(If nothing displays, try changing it to `0x3F` in the code.)

---

### 📦 IoT Power Relay
| Relay Pin | Arduino Pin |
|-----------|-------------|
| IN        | D8          |
| GND       | GND         |
| VCC       | 5V          |
| Load      | Pump plugs into NO (Normally Open) outlet |

---

## 📄 Code Overview

The Arduino sketch:
- Initializes the LCD and serial monitor
- Displays `"Next watering:"` and a countdown
- Every 24 hours:
  - Turns on the relay (and pump) for 20 seconds
  - Updates the display to say `"Watering now..."`

Change this line to adjust how often it waters:

```cpp
#define INTERVAL_MS 86400000UL  // 24 hours in milliseconds
