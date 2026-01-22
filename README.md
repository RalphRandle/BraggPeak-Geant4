# Bragg Peak Simulation with Geant4 ⚛️

This project simulates the energy deposition profiles of **Protons** and **X-rays (Gamma)** in a water phantom using the Geant4 toolkit. It demonstrates the fundamental advantage of proton therapy (the Bragg Peak) compared to conventional X-ray radiotherapy.

## 🎯 Project Goal
To visualize and compare two distinct physical interactions:
1.  **Protons:** Depositing maximum energy at a specific depth (Bragg Peak).
2.  **X-rays (Gamma):** Exhibiting exponential attenuation (Beer-Lambert law) without a peak.

## 🚀 How to Run

### 1. Build the Project
Standard CMake build process:
```bash
mkdir build && cd build
cmake ..
make
cd Release
```

### 2. Run Simulations
You can run the simulation in two different modes using the provided macro files.

## 🅰️ Proton Mode (Bragg Peak)
Simulates 150 MeV protons.
```bash
./bragg.exe proton.mac
```
Output: You will see a sharp peak in energy deposition at the end of the range.

## 🅱️ X-Ray Mode (Gamma Attenuation)
Simulates 6 MeV photons (Gamma).

```bash
./bragg.exe xray.mac
```
Output: You will see a continuously decreasing energy profile (exponential decay).

### 3. Visualization
To run interactively with OpenGL visualization:

```bash
./bragg.exe
```
Then, in the simulation session:

```bash
/control/execute proton.mac
```
or

```bash
/control/execute xray.mac
```


### 📂 File Structure
src/: Source codes (DetectorConstruction, PhysicsList, etc.)

proton.mac: Macro for Proton simulation (150 MeV).

xray.mac: Macro for X-ray/Gamma simulation (6 MeV).

vis.mac: Visualization settings.

### 📊 Results
The simulation generates root files (Bragg.root) which can be analyzed to plot Energy Deposition vs Depth (Z) graphs.

Developed by Ralph Randle
