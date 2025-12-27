##include "sensors.h"

void setup() {
    Serial.begin(115200);
    Serial.println("VoltGuard-PHD Starting...");
    initSensors();
}

void loop() {
    SensorData data = readSensors();
    Serial.print("Voltage: "); Serial.println(data.voltage);
    Serial.print("Current: "); Serial.println(data.current);
    Serial.print("Temperature: "); Serial.println(data.temperature);
    Serial.println("---");
    delay(1000);
}
include <Arduino.h>

void setup() {
  // Initialize serial for debugging
  Serial.begin(115200);
  Serial.println("VoltGuard-PHD Starting...");
}

void loop() {
  // For now, just wait
  delay(1000);
  Serial.println("Loop running...");
}

