#ifndef SENSORS_H
#define SENSORS_H

// Structure to hold all sensor readings
struct SensorData {
    float voltage;      // real hardware

};

// Initialize sensors
void initSensors();

// Read all sensors (returns SensorData)
SensorData readSensors();

#endif

