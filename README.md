# MQ2-Library

Arduino library for **MQ-2 Gas Sensor** (LPG, CO, and Smoke) created by **Najikhul Umam**.  
This library simplifies reading gas concentration in **ppm** using calibration equations derived from the MQ-2 datasheet.  

## ✨ Features
- Automatic calibration of **Ro** value  
- Supports detection of **LPG**, **CO**, and **Smoke**  
- Calculates ppm using **log-log regression** (slope & intercept from datasheet curves)  
- Simple and easy-to-use syntax  

## 📂 Library Structure
```cpp
MQ-2_Library_Najikhul/
├── examples/
│ └── MQ2_Test/
│     └── MQ2_Test.ino
├── src/
│ ├── MQ2_NAJIKHUL_UMAM.h
│ └── MQ2.cpp
├── LICENSE
└── README.md
└── library.properties
```
## ⚡ Installation
1. Clone this repository or download it as ZIP  
2. Extract the folder and move it to:  
    Documents/Arduino/libraries/
3. Or in Arduino IDE → **Sketch → Include Library → Add .ZIP Library…** and select the ZIP file downloaded

## 🛠️ Usage Example
```cpp
#include <MQ2_NAJIKHUL_UMAM.h>

MQ2 mq(A0); // create MQ2 sensor object on analog pin A0

void setup() {
Serial.begin(9600);
mq.begin(); // calibrate the sensor
}

void loop() {
float ratio = mq.getRatio();

float lpg   = mq.getGasPPM(ratio, GAS_LPG);
float co    = mq.getGasPPM(ratio, GAS_CO);
float smoke = mq.getGasPPM(ratio, GAS_SMOKE);

Serial.print("LPG: "); Serial.print(lpg); Serial.println(" ppm");
Serial.print("CO: "); Serial.print(co); Serial.println(" ppm");
Serial.print("Smoke: "); Serial.print(smoke); Serial.println(" ppm");

delay(1000);
}
```
## 📊 Gas Calculation
Gas concentration is calculated using logarithmic equations from the MQ-2 datasheet:
```cpp
log10(ppm) = m * log10(Rs/Ro) + b
```
Where the slope (m) and intercept (b) values are:
```
| Gas   | m      | b     |
| ----- | ------ | ----- |
| LPG   | -0.546 | 1.599 |
| CO    | -0.451 | 1.581 |
| Smoke | -0.549 | 1.741 |
```
## 📜 License
This project is licensed under the MIT License.
