#include <Arduino.h>
#include "sensors.h"

struct InferenceResult {
  int healthScore;
  int state;      // 0=healthy,1=degrading,2=critical
  int confidence;
};

InferenceResult inferHealth(float voltage) {
  InferenceResult r;

  float deviation = abs(voltage - 230.0) / 230.0;
  int score = 100 - (deviation * 200);
  score = constrain(score, 0, 100);

  r.healthScore = score;

  if (score > 80) r.state = 0;
  else if (score > 50) r.state = 1;
  else r.state = 2;

  r.confidence = 85 + random(0, 10);
  return r;
}

void setup() {
  Serial.begin(115200);
  pinMode(34, INPUT); 
  analogReadResolution(12);           // 0–4095
analogSetPinAttenuation(34, ADC_11db); // allows up to ~3.3V
  initSensors();
}

void loop() {
  SensorData data = readSensors();
  InferenceResult res = inferHealth(data.voltage);
  
  Serial.print("RAW voltage value: ");
  Serial.println(data.voltage);

  Serial.print("{\"health\":");
  Serial.print(res.healthScore);
  Serial.print(",\"state\":");
  Serial.print(res.state);
  Serial.print(",\"confidence\":");
  Serial.print(res.confidence);
  Serial.println("}");

  delay(1000);
}
