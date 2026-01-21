#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

// =============================================================
// EN: Detector Construction Class
// TR: Dedektör Ýnþa Sýnýfý
// =============================================================
// EN: Defines the geometry of the simulation (World, Phantom, etc.)
//     and assigns sensitive detectors or user limits (Step Limiter).
// TR: Simülasyonun geometrisini (Dünya, Fantom vb.) tanýmlar
//     ve hassas dedektörleri veya kullanýcý sýnýrlarýný (Adým Sýnýrlayýcý) atar.
class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    DetectorConstruction() = default;
    ~DetectorConstruction() override = default;

    // EN: The main method where geometry is built.
    // TR: Geometrinin inþa edildiði ana metot.
    G4VPhysicalVolume* Construct() override;
};

#endif