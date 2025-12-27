# VoltGuard-PHD — System Overview

VoltGuard-PHD is a prototype electrical health-monitoring system designed for edge devices (ESP32 or similar).
Its goal is to continuously measure electrical signals, extract degradation patterns, diagnose device conditions,
and predict failures before they occur.

This project simulates multi-sensor capability but currently only uses:
- Voltage sensing (real hardware)
- Current sensing (real hardware)

Other sensors (temperature, humidity, vibration, magnetic flux) will be simulated at the software level to demonstrate
multi-modal predictive intelligence.

## Layers of the System (High-Level)

Layer 1 — Hardware Sampling & Acquisition  
Layer 2 — Sensor Inputs (real + simulated)  
Layer 3 — Feature Extraction (THD, ripple, rate-of-change)  
Layer 4 — Diagnostic Engine (rules-based for prototype)  
Layer 5 — Predictions + Explanation  
Layer 6 — Actions (alerts, flags, UI messages)

## What This Document Is For
This file is a human-readable explanation of what VoltGuard-PHD *is about.*
All future technical details will live inside additional markdown docs.
