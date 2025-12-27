#include "sensors.h"
#include <Arduino.h>

// Initialize sensors (placeholder for now)
void initSensors() {
    Serial.println("Sensors initialized (fake + real placeholders)");
}

// Read sensors (fake values for demo purposes)
SensorData readSensors() {
    SensorData data;

    // Simulate voltage & current reading
    data.voltage = 230.0 + random(-5, 5) * 0.1; // 229.5V - 230.5V
    data.current = 1.5 + random(-5, 5) * 0.01;  // 1.45A - 1.55A

    // Simulate other sensors
    data.temperature = 25.0 + random(-50, 50) * 0.1;   // 20°C - 30°C
    data.vibration = random(0, 100) * 0.01;             // 0 - 1 g
    data.humidity = 40.0 + random(-50, 50) * 0.1;       // 35% - 45%
    data.magneticFlux = 0.5 + random(-50, 50) * 0.01;   // 0.0 - 1.0 arbitrary units

    return data;
}

