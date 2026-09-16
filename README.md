# Reaction Time Tester

## Table of Contents

1.  [Overview](#overview)
2.  [Hardware Components](#hardware-components)
3.  [Pin Mapping](#pin-mapping)
4.  [How to Run](#how-to-run)


## 1. Overview

This project utilizes an Arduino board programmed in C++ (via Arduino IDE). To check a user's reaction speed this project uses 4 LEDs that will light up 3 seconds after user pressed the start button. To successfully test the reaction, user needs to press the button next to the corresponding LED (that lit up) within 3 seconds to pass the test. Results and real-time guidance are displayed on an LCD screen. To run the test again, simply press the start button after the current round finishes.


## 2. Hardware Components

| Component | Quantity | Comments |
| ---- | ----- | ----- |
| Arduino Uno R3 | 1 | It is possible to use different Arduino board |
| LCD HD44780 | 1 | To display instructions |
| Red LED | 1 | - |
| Blue LED | 1 | - |
| Yellow LED | 1 | - |
| Green LED | 1 | - |
| Buttons | 4 | - |
| Resistor $1\ \mathsf{k\Omega}$ | 4 | Limiting current for LEDs |
| Potentiometer $5\ \mathsf{k\Omega}$ | 1 | To control LCD's contrast |
| Breadboard | 1 | - |
| Jumper wires | - | - |


## 3. Pin Mapping

The LCD pins are listed in physical order (from left to right on the display module). 

| LCD pin | Arduino pin or power supply | Comments |
|----|-----|-----|
|1. VSS/GND | GND | - |
|2. VDD | +5V | - |
|3. V0 | Potentiometer | Connect to the wiper (middle pin) of the potentiometer | 
|4. RS | 10 | Arduino pin |
|5. RW | GND | - |
|6. E | 9 | Arduino pin |
|7-10. | - | Not connected |
|11. D4 | 8 | Arduino pin | 
|12. D5 | 7 | Arduino pin |
|13. D6 | 6 | Arduino pin |
|14. D7 | 5 | Arduino pin |
|15. A | +5V | - |
|16. K | GND | - |

Since all digital pins were in use, three of the LEDs were connected to analog input pins. Also if you are using an LCD module other than the HD44780, make sure to check whether pin A (backlight anode) requires an external current-limiting resistor.

| Component | Arduino pin | Comments |
| ---- | ----- | ----- |
| Blue LED | A0 | - |
| Red LED | A1 | - |
| Yellow LED | A2 | - |
| Green LED | 3 | - |
| (Blue) Button | 13 | button next to the blue LED |
| (Red) Button | 12 | button next to the red LED |
| (Yellow) Button | 11 | button next to the yellow LED |
| (Green) Button | 4 | button next to the green LED |
| Start Button | 2 | button responsible for the start of the reaction test |

Note: Remember to connect power (5V and GND) to the outer pins of the potentiometer so that it functions properly as a voltage divider for the LCD contrast.


## 4. How to Run

### Step 1

Install and launch an IDE capable of compiling and uploading Arduino code (e.g., [Arduino IDE](https://www.arduino.cc/en/software/)).

### Step 2 

Connect all components according to the pin mapping above. 

### Step 3 

Connect your board to the PC. Upload and run the code. 