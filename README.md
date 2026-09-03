⚡ PIC16F877A Embedded C Projects

Bare-Metal Embedded C • Register-Level Programming • PIC16F877A
🧩 About This Repository

This repository contains a collection of bare-metal Embedded C projects and peripheral drivers developed for the Microchip PIC16F877A 8-bit microcontroller.
The projects demonstrate practical knowledge of GPIO, ADC, USART, PWM, Timers, Interrupts, EEPROM, LCD, Keypad, and sensor interfacing using low-level register configuration.
💡 Focus: Understand the hardware → Configure registers → Write driver → Test → Debug

🛠️ Technology Stack
Category	Technology
🧠 Microcontroller	PIC16F877A
💻 Programming Language	Embedded C
⚙️ Compiler	Microchip XC8
🖥️ IDE	MPLAB X IDE
🔬 Simulation	Proteus VSM
🔧 Programmer	PICkit
🏗️ Programming Style	Bare-Metal / Register-Level

📁 Project Structure
PIC16F877A-Embedded-C-Projects/
│
├── 01_GPIO_Basics/
│   ├── LED_Blink/
│   ├── Push_Button/
│   └── Relay_Control/
│
├── 02_LCD_Display/
│   ├── LCD_4Bit/
│   └── LCD_8Bit/
│
├── 03_ADC_Read/
│   ├── ADC_Single_Channel/
│   └── ADC_Multi_Channel/
│
├── 04_UART_Communication/
│   ├── UART_TX/
│   ├── UART_RX/
│   └── UART_PC_Communication/
│
├── 05_PWM_Control/
│   ├── LED_Brightness/
│   └── DC_Motor_Control/
│
├── 06_Timer_Applications/
│   ├── Timer0/
│   ├── Timer1/
│   └── Timer2/
│
├── 07_Interrupts/
│   ├── External_Interrupt/
│   └── Timer_Interrupt/
│
├── 08_EEPROM/
│   ├── EEPROM_Write/
│   └── EEPROM_Read/
│
├── 09_Keypad_Interface/
│   └── 4x4_Keypad/
│
└── 10_Sensor_Interface/
    ├── Temperature_Sensor/
    └── Analog_Sensor/

🔌 Peripheral Drivers
🟢 GPIO
Digital input/output programming using PIC16F877A TRIS and PORT registers.
LED blinking
Push-button input
Relay control
Digital I/O

🖥️ LCD
16x2 LCD driver supporting:
4-bit mode
8-bit mode
Command/Data control
Cursor positioning
String and numeric display

📊 ADC
Analog signal acquisition using the built-in ADC module.
Potentiometer reading
Temperature sensors
Analog voltage measurement
Multi-channel ADC

📡 USART
Serial communication between PIC16F877A and external devices.
TX/RX communication
Baud-rate configuration
Character transmission
String transmission
PC communication

⚡ PWM
PWM generation using the CCP module.
DC motor speed control
LED brightness control
PWM signal generation

⏱️ Timers
Timer configuration and timing applications using:
Timer0
Timer1
Timer2

🚨 Interrupts
Interrupt-driven programming using:
External interrupts
Timer interrupts
Peripheral interrupts

💾 EEPROM
Internal EEPROM programming for non-volatile data storage.

🔢 Keypad
4x4 matrix keypad interfacing and key detection.

🧪 Development & Testing Flow
       ┌───────────────┐
       │   Write C     │
       │     Code      │
       └───────┬───────┘
               │
               ▼
       ┌───────────────┐
       │   XC8 Compile │
       └───────┬───────┘
               │
               ▼
       ┌───────────────┐
       │ Generate HEX  │
       └───────┬───────┘
               │
               ▼
       ┌───────────────┐
       │ Proteus / HW  │
       │    Testing    │
       └───────┬───────┘
               │
               ▼
       ┌───────────────┐
       │ Debug & Verify│
       └───────────────┘

🎯 Skills Demonstrated
Embedded C programming
PIC16F877A architecture
Register-level programming
GPIO configuration
ADC programming
USART communication
PWM generation
Timer configuration
Interrupt handling
EEPROM programming
LCD interfacing
Keypad interfacing
Sensor interfacing
Proteus simulation
Hardware debugging

🚀 Getting Started
1. Clone the Repository
git clone https://github.com/your-username/PIC16F877A-Embedded-C-Projects.git
2. Open in MPLAB X IDE
Open the required project directory in MPLAB X IDE.
3. Select XC8 Compiler
Configure the project to use the Microchip XC8 compiler.
4. Build the Project
Clean and Build Project
        ↓
Generate HEX File
5. Simulate or Program
Load the generated .hex file into Proteus VSM or program the PIC16F877A using a compatible programmer.

🏆 Repository Highlights
Feature	Status
GPIO	✅
LCD	✅
ADC	✅
USART	✅
PWM	✅
Timers	✅
Interrupts	✅
EEPROM	✅
Keypad	✅
Sensors	✅
Proteus Simulation	✅
👨‍💻 Developer

Gowtham V
Embedded Firmware Engineer
Embedded C • Microcontrollers • Bare-Metal Firmware • Hardware Interfacing
⚡ Learn Hardware. Write Firmware. Build Embedded Systems
