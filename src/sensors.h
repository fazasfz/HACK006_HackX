#ifndef SENSORS_H
#define SENSORS_H

// Structure to hold all sensor readings
struct SensorData {
    float voltage;      // real hardware
    float current;      // real hardware
    float temperature;  // simulated
    float vibration;    // simulated
    float humidity;     // simulated
    float magneticFlux; // simulated
};

// Initialize sensors
void initSensors();

// Read all sensors (returns SensorData)
SensorData readSensors();

#endif

