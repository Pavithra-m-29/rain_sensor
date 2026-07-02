# IoT Rain Monitoring System using NodeMCU ESP8266

## Project Overview
This project demonstrates an Internet of Things (IoT) based **Rain Monitoring System** built using the **NodeMCU ESP8266 (ESP-12E)** development platform. The system uses a raindrop sensor to monitor precipitation levels in real-time. When moisture/rain is detected, it triggers a local physical alarm system (Buzzer and LED Indicator) and simultaneously updates an interactive web dashboard hosted dynamically on the local network server.

---

## Components Used
* **NodeMCU ESP8266 (ESP-12E Module)** (Wi-Fi Microcontroller)
* **Raindrop Sensor Module** (with LM393 Comparator Board)
* **Piezo Buzzer** (Acoustic Alarm)
* **LED** (Visual Alarm Indicator)
* **Breadboard & Jumper Wires**
* **Smartphone / Laptop Web Browser** (For Live Dashboard Monitoring)

---

## Circuit Configuration

| Component / Device | NodeMCU Pin | Description |
|---------------------|-------------|-------------|
| **Raindrop Sensor (Analog Out)** | A0 | Reads analog moisture values (0 = Max Wet, 1023 = Dry) |
| **Piezo Buzzer** | D5 | Audio alert output (Active when rain is detected) |
| **LED Indicator** | D6 | Visual flash alert (Active when rain is detected) |

*Note: The raindrop sensor board converts threshold levels. As water droplets collect on the sensing pad, the resistance drops, pulling the analog output value down towards `0`, indicating a "RAIN DETECTED" state.*

---

## Features
* **Real-time Web Dashboard:** Hosts a live network web portal displaying current raw sensor values, status text (`NO RAIN` / `RAIN DETECTED`), and color-coded indicator shapes.
* **Dual-Alert Feedback Mechanism:** Seamlessly integrates synchronized local audio-visual alerts (Buzzer beep + LED glow) with global network adjustments.
* **Smart Threshold Logic:** Calibrates precise data margins via coding logic to distinguish between moisture humidity changes and immediate direct downpours.

---

## Software Requirements
* **Arduino IDE** (With the ESP8266 Core platform package set up)
* **ESP8266WebServer Library** (For hosting the live responsive user interface page)

---

## How to Set Up and Run
1. Wire up the sensor module, buzzer, and LED configurations onto the breadboard as showcased.
2. Open the control program script (`.ino`) file within your **Arduino IDE**.
3. Fill in your localized Wi-Fi access configuration parameters (`SSID` and `Password`).
4. Upload the compiled binary code onto the connected NodeMCU microcontroller unit.
5. Check the **Serial Monitor** at a `115200` baud rate to fetch the system's assigned web IP address.
6. Launch an internet browser tab on your mobile or computer device, enter the IP address, and place water droplets on the sensor surface area to observe the dynamic automated updates.

---

## Author
Pavithra M
