#include "sensors.h"
#include <Arduino.h>

#define ANALOG_PIN_VOLTAGE 34
#define ADC_MAX 4095.0
#define ADC_REF 3.3

// ⚠️ TEMP calibration factor (you will tune this)
#define ZMPT_CALIBRATION 100.0  

void initSensors() {
    pinMode(ANALOG_PIN_VOLTAGE, INPUT);
    analogReadResolution(12);   // ESP32 default, but be explicit
    Serial.println("Sensors initialized (ZMPT101B active)");
}

SensorData readSensors() {
    SensorData data;

    int raw = analogRead(34);
    Serial.print("ADC RAW: ");
    Serial.println(raw);

    // ZMPT output is centered around mid-point
    const int ADC_MID = 2048;   // ~1.65V
    int signal = raw - ADC_MID;

    // Convert ADC to voltage (ADC → volts)
    float voltage_adc = (signal / 4095.0) * 3.3;

    // Calibration factor (START WITH 100, adjust later)
    float voltage_real = abs(voltage_adc) * 100.0;


    data.voltage = voltage_real;

    return data;
}
