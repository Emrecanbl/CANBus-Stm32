# CANBus Stm32
CANBus-Stm32
This project demonstrates communication between two STM32 microcontrollers and an Arduino Pro Mini using TJA1050 transceivers over CANbus. The project involves controlling a fan connected to one STM32 and a servo and stepper motor connected to the Arduino. The Arduino Pro Mini uses the MCP2515 via SPI for CAN bus support.

Table of Contents
Introduction
Hardware Requirements
Software Requirements
Setup
Usage
Code Overview
Contributing
License
Introduction
The purpose of this project is to demonstrate how to set up and use CANbus communication between multiple microcontrollers. In this example, we use two STM32 microcontrollers and an Arduino Pro Mini to control various devices.

Hardware Requirements
2 x STM32 microcontrollers (e.g., STM32F103C8T6)
1 x Arduino Pro Mini
3 x TJA1050 CAN transceivers
1 x MCP2515 CAN module (for Arduino Pro Mini)
1 x Fan
1 x Servo motor
1 x Stepper motor
CANbus wiring and connectors
Breadboard and jumper wires
Software Requirements
STM32CubeIDE or any compatible STM32 development environment
Arduino IDE
CAN library for STM32 (e.g., STM32 HAL CAN library)
CAN library for Arduino (e.g., CAN)
MCP2515 library for Arduino
Setup
STM32 Microcontrollers
![Sample](https://github.com/Emrecanbl/CANBus-Stm32/blob/main/Foto_1.jpg?raw=true)
Wiring:

Connect the TJA1050 transceivers to the STM32 microcontrollers.
Connect the fan to one of the STM32 microcontrollers.
Ensure CAN_H and CAN_L lines are correctly connected between the TJA1050 transceivers.
Programming:

Use STM32CubeIDE to set up the CAN peripheral and GPIOs.
Flash the provided firmware to the STM32 microcontrollers.
Arduino Pro Mini
Wiring:

Connect the MCP2515 CAN module to the Arduino Pro Mini via SPI.
Connect the TJA1050 transceiver to the MCP2515 module.
Connect the servo and stepper motor to the Arduino Pro Mini.
Programming:

Use the Arduino IDE to upload the provided Arduino sketch to the Arduino Pro Mini.
Ensure the MCP2515 library is included in the Arduino sketch.
Usage
Power up the STM32 microcontrollers and the Arduino Pro Mini.
The STM32 microcontrollers will start communication over CANbus.
You can control the fan connected to the STM32 and the servo and stepper motor connected to the Arduino via CAN messages.
Code Overview
STM32 Code
F103_CANBus_Sender: Reads values from a joystick and button and sends both to the receiver device.
F103_CANBus_Receiver: Receives CAN messages and controls the fan based on received commands.
Arduino Code
Arduino_CANBus_Gripper:
Initializes the CAN interface using the MCP2515 module.
Sends and receives CAN messages.
Controls the servo and stepper motor based on received CAN messages.
![Sample](https://github.com/Emrecanbl/CANBus-Stm32/blob/main/GIF.gif?raw=true)
Contributing
Contributions are welcome! Please fork this repository and submit a pull request for any enhancements or bug fixes.

License
This project is licensed under the MIT License. See the LICENSE file for more details.


![Sample](https://github.com/Emrecanbl/CANBus-Stm32/blob/main/Foto_1.jpg?raw=true)
