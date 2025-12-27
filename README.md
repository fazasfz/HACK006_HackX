# HACK006_HackX
#    VoltGuard-PHD — Predictive Health Diagnostics for Electrical Systems

VoltGuard-PHD is an edge-based system that continuously monitors electrical signals, extracts degradation patterns,
diagnoses potential failures, and predicts when an appliance or line may fail — before it happens.

This prototype is designed for hackathon demonstration and currently:
- Uses **real voltage + current sensors**
- Simulates additional sensor values (temperature, humidity, vibration, magnetic flux)
- Runs diagnostic rules and generates a **Health Score**
- Will later include a UI dashboard + Alerts

## Why this matters
There is currently no affordable consumer-grade device that watches:
- the **electrical environment**
- **itself**
- **and** predicts degradation proactively

VoltGuard-PHD bridges that gap by combining signal analysis + diagnostic logic directly on an edge microcontroller.

## System Layers (Short)
1. Hardware Data Sampling  
2. Sensor Inputs  
3. Feature Extraction  
4. Diagnostic Engine  
5. Predictions + Explanation  
6. Actions + UI  

## Current Stage
Software scaffold is being built first — real hardware integration comes next.
