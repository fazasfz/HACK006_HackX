#ifndef FEATURE_H
#define FEATURE_H

#include "sensors.h"

// Structure to hold extracted features
struct Features {
    float voltageDeviation;    // % deviation from baseline
    float currentSpike;        // instantaneous change
    float temperatureTrend;    // difference from previous
    float anomalyScore;        // combined score
};

// Initialize feature extraction
void initFeatures();

// Extract features from sensor data
Features extractFeatures(const SensorData &data);

#endif

