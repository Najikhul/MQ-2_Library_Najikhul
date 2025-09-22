#ifndef MQ2_NAJIKHUL_H
#define MQ2_NAJIKHUL_H

#include <Arduino.h>

#define RL_VALUE 5.0              // RL = 5kΩ sesuai datasheet
#define RO_CLEAN_AIR_FACTOR 9.83  // faktor Ro di udara bersih (datasheet MQ-2)

enum GasType {
    GAS_LPG,
    GAS_CO,
    GAS_SMOKE
};

class MQ2 {
public:
    MQ2(int pin);
    void begin();
    float readRs();
    float calibrate();
    float getRatio();
    float getGasPPM(float ratio, GasType gas);

private:
    int _pin;
    float Ro;
};

#endif
