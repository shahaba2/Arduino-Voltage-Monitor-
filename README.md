# Arduino Voltage Monitoring and Alarm System

An Arduino Uno R3 project that reads an analog voltage, displays the reading on a 16x2 LCD, and uses LEDs to indicate normal or alarm status. The alarm latches when the measured voltage rises above 3.1 V and remains active until the voltage falls below 2.9 V and the reset button is pressed.

## Features

- Reads the analog input on `A0` and displays voltage to two decimal places.
- Shows `ALARM` or `NORMAL` status on the LCD and prints readings to the Serial Monitor.
- Turns on the red LED during an alarm and the green LED during normal operation.
- Uses separate alarm and reset thresholds to provide hysteresis and prevent the alarm from clearing until the input is safely below the reset threshold.

## Hardware

- Arduino Uno R3
- 16x2 LCD compatible with the Arduino `LiquidCrystal` library
- Potentiometer for the monitored analog input
- Red and green LEDs with suitable current-limiting resistors
- Momentary reset button
- Breadboard and jumper wires

## Connections

The LCD pin assignments below match the sketch. Connect LCD power and contrast pins according to the LCD module's documentation.

| Component | Arduino connection |
|---|---|
| LCD RS | D12 |
| LCD Enable (E) | D11 |
| LCD D4 | D5 |
| LCD D5 | D4 |
| LCD D6 | D3 |
| LCD D7 | D6 |
| Red LED | D8 |
| Green LED | D7 |
| Reset button | D2 and GND |
| Analog input | A0 |

With the sketch's `INPUT_PULLUP` configuration, the reset button connects D2 to GND when pressed. For a potentiometer used as the input source, connect its outer terminals to 5 V and GND and its wiper to A0. Keep the input voltage within the Arduino Uno's analog input limits.

## How It Works

The sketch converts the 10-bit `analogRead(A0)` result to voltage using `5.0 / 1023.0`, so the displayed reading assumes a 5 V analog reference:

- **Voltage above 3.1 V:** The alarm is activated.
- **Voltage below 2.9 V and reset button pressed:** The alarm is cleared.
- **Otherwise:** The current alarm state is retained.

When the alarm is active, the red LED is on and the green LED is off. When inactive, the green LED is on and the red LED is off. Voltage and status are also sent to the Serial Monitor at 9600 baud.

## Upload and Run

1. Open `PowerMonitor_V2.ino` in the Arduino IDE.
2. Select **Arduino Uno** as the board and choose the connected port.
3. Ensure the `LiquidCrystal` library is available (it is included with the Arduino IDE).
4. Upload the sketch.
5. Optionally open the Serial Monitor and set its baud rate to **9600**.

## Applications and Learning

The project demonstrates principles used in voltage monitoring and alarm systems for applications such as battery management, power supplies, and industrial equipment. It provides practice with Arduino C/C++, analog-to-digital conversion, LCD integration, circuit wiring, alarm logic, and testing and debugging.

> **Safety note:** This is an educational low-voltage prototype, not a certified protection device. Do not connect it directly to mains electricity or rely on it to protect real equipment.
