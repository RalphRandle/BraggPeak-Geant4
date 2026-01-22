# Proton Bragg Peak Simulation (Geant4)

This project simulates the energy deposition of **150 MeV protons** in a water phantom using the **Geant4** toolkit. It demonstrates the characteristic **Bragg Peak** effect used in proton therapy.

### 🚀 Features
- **Particle:** Proton (150 MeV)
- **Phantom:** Water Box (20x20x20 cm)
- **Physics List:** QGSP_BIC_EMY (Optimized for EM physics)
- **Analysis:** ROOT histograms for energy deposition (Step Limiter included).

### 🛠️ Usage
1. Clone the repository.
2. Build with CMake.
3. Run `./BraggSim`
