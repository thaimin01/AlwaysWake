
# AlwaysWake
An alarm clock that comes with 4 mechanical switches, a 2.25 inch TFT screen, and runs on rp2040

Features:

- Alarm setting
- Custom music, chirp
- Pomodoro clock
- Countdown clock

This is your average clock, but it's not as annoying as your iphone alarm

Why?

because, you can customize the alarm pattern
Setting up alarm in a quick and easy way
And pomodoro, Countdown for your everyday uses

Schematic

<img width="1186" height="640" alt="schematic" src="https://github.com/user-attachments/assets/7fa9847c-068f-4abb-a2d4-687e3d8e3a2a" />

PCB

<img width="921" height="556" alt="PCB" src="https://github.com/user-attachments/assets/6cde22c8-88b6-4de1-bb89-bf2a05059fc9" />

Case

<img width="986" height="753" alt="case" src="https://github.com/user-attachments/assets/b4a8f751-a214-4950-800d-06b223b73d11" />

<img width="1096" height="760" alt="casewithpcb" src="https://github.com/user-attachments/assets/b206cca0-f403-49cc-adbd-a1ff38e4432b" />


Bill of materials

| Reference | Qty | Value | DNP | Exclude from BOM | Exclude from Board | Exclude from Simulation | Exclude from Position Files | Footprint | Datasheet |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| BZ1 | 1 | Buzzer | | | | | ${EXCLUDE_FROM_POS_FILES} | Buzzer_Beeper:Buzzer_12x9.5RM7.6 | |
| J1 | 1 | Conn_01x08_Pin | | | | | ${EXCLUDE_FROM_POS_FILES} | Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical | |
| MX1, MX2, MX4, MX5 | 4 | MX_SW_HS | | | | | ${EXCLUDE_FROM_POS_FILES} | marbastlib-xp-mx:SW_MX_Reversible_1u | |
| U1 | 1 | XIAO-RP2040-SMD | | | | | ${EXCLUDE_FROM_POS_FILES} | Seeed_Studio_XIAO_Series:XIAO-RP2040-SMD | |

Coding interface

Code by a Human, on Arduino IDE, And C++ !!!
