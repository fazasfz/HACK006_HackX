#include "feature.h"
#include <Arduino.h>

// Baseline values for demo (fixed for predictability)
float baselineVoltage = 230.0;
float previousCurrent = 1.5;
float previousTemperature = 25.0;

void initFeatures() {
    Serial.println("Feature extraction initialized");
}

Features extractFeatures(const SensorData &data) {
    Features f;

    // Voltage deviation %
    f.voltageDeviation = ((data.voltage - baselineVoltage) / baselineVoltage) * 100.0;

    // Current spike = difference from previous
    f.currentSpike = data.current - previousCurrent;
    previousCurrent = data.current;

    // Temperature trend
    f.temperatureTrend = data.temperature - previousTemperature;
    previousTemperature = data.temperature;

    // Simple anomaly score (weighted sum for demo)
    f.anomalyScore = abs(f.voltageDeviation) * 0.6 + abs(f.currentSpike) * 20 + abs(f.temperatureTrend) * 1.5;

    return f;
}

