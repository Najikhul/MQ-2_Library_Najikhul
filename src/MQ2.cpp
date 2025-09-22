#include "MQ2_NAJIKHUL_UMAM.h"
#include <math.h>

// Konstruktor
MQ2::MQ2(int pin) {
    _pin = pin;
}

// Inisialisasi sensor
void MQ2::begin() {
    Ro = calibrate();
}

// Baca nilai ADC dan hitung Rs
float MQ2::readRs() {
    int adcValue = analogRead(_pin);
    float vrl = adcValue * (5.0 / 1023.0);  // konversi ADC ke volt
    float rs = (5.0 - vrl) * RL_VALUE / vrl; 
    return rs;
}

// Kalibrasi sensor di udara bersih
float MQ2::calibrate() {
    float rs = 0.0;
    for (int i = 0; i < 50; i++) {
        rs += readRs();
        delay(50);
    }
    rs = rs / 50.0;
    return rs / RO_CLEAN_AIR_FACTOR;
}

// Hitung Rs/Ro
float MQ2::getRatio() {
    return readRs() / Ro;
}

// Konversi Rs/Ro ke ppm berdasarkan slope & intercept
float MQ2::getGasPPM(float ratio, GasType gas) {
    float m, b;

    switch (gas) {
        case GAS_LPG:
            m = -0.546; b = 1.599;
            break;
        case GAS_CO:
            m = -0.451; b = 1.581;
            break;
        case GAS_SMOKE:
            m = -0.549; b = 1.741;
            break;
        default:
            return -1;
    }

    float log_ppm = (log10(ratio) - b) / m;
    return pow(10, log_ppm);
}
