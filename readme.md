# ESP32 Servo Motor Control via Web Interface

This project demonstrates how to control a servo motor using an ESP32 microcontroller with a web interface. You can turn the servo to specific angles by accessing a web page served by the ESP32.

---

## Features

- Serve a web page accessible via local network
- Control servo motor position through a slider input

---

## Hardware Requirements

- ESP32 development board
- Servo motor (e.g., SG90 or similar)
- Power supply suitable for the servo
- Jumper wires

## Software Requirements

- PlatformIO IDE (recommended)
- ESP32 board package installed in PlatformIO

---

## Wiring

| ESP32 Pin | Connection            | Description                  |
|------------|------------------------|------------------------------|
| GPIO 21    | Servo Signal Pin       | Connect to servo control wire|
| 3.3V, 5V or Vin| Power Supply for Servo | Depending on servo specs     |
| GND        | Ground                 | Common ground                |

*Note:- Ensure the servo power supply is sufficient and common ground is shared with ESP32.*

---

## Setup Instructions

### 1. Clone or Download the Repository

```bash
git clone https://github.com/akarshit-1609/Servo_Motor_Control_via_Web_Interface_with_ESP32.git
```

### 2. Open in PlatformIO:

Open the cloned project in your preferred IDE with the PlatformIO extension installed (e.g., VS Code).

### 3. Configure `platformio.ini`

Make sure to select the correct board:

```ini
[env:nodemcu-32s]
platform = espressif32
board = nodemcu-32s
framework = arduino
monitor_speed = 115200
```

### 4. Configure Variables:

Before uploading the code to your ESP32, you need to configure some variables, particularly the GPIO pin.

*   **Locate the configuration:** Open the `src/main.cpp` file.
*   **Find the variable:** Look for a line similar to this:

    ```c++
    const char* ssid = "Your_ssid";// Replace with your custom ssid
    const char* password = "your_password"; // Replace with your password
    const int servo_pin = 21; // Replace with servo signal GPIO pin
    ```

*   **Replace the value:** Change the `21` to the actual GPIO pin number where your servo signal pin is connected on your ESP32 board. Refer to your ESP32 board's pinout diagram if you are unsure.

### 5. Build and Upload:

*   Connect your ESP32 board to your computer via USB.
*   In PlatformIO, click the "Build" button to compile the project.
*   Click the "Upload" button to upload the compiled code to your ESP32.

---


### 6. Connect to Network

Once the code is uploaded, connect any device with esp32 wifi by ssid and password given in the code after open the browser and Go to url http://192.168.0.1 and change the slider range to move the servo.



## Usage

- The web page will display a slider input to set the servo angle (0-180 degrees).
- Adjust the slider to move the servo to the desired position.

---

## Demo

https://github.com/user-attachments/assets/8600a84c-28e9-4240-9308-aaa8311d9b51

---

## Notes

- Adjust `servoPin` if you connect the servo to a different GPIO.
- Ensure your servo power supply can handle the current draw.
- You can expand the web interface for additional features.

---


## References

- [ESPAsyncWebServer Library](https://github.com/esphome/ESPAsyncWebServer)
- [ESP32Servo library](https://github.com/madhephaestus/ESP32Servo)

---

Enjoy controlling your servo motor via a simple web interface!
