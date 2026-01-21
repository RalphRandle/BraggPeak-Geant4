#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4UserLimits.hh" // EN: Required for Step Limiter / TR: Adým Sýnýrlayýcý için gerekli

G4VPhysicalVolume* DetectorConstruction::Construct() {

    // =============================================================
    // EN: Material Definitions
    // TR: Malzeme Tanýmlarý
    // =============================================================
    G4NistManager* nist = G4NistManager::Instance();

    // EN: Use standard NIST materials: Air for World, Water for Phantom.
    // TR: Standart NIST malzemelerini kullan: Dünya için Hava, Fantom için Su.
    G4Material* worldMat = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* waterMat = nist->FindOrBuildMaterial("G4_WATER");

    // =============================================================
    // EN: 1. World Volume (Experimental Hall)
    // TR: 1. Dünya Hacmi (Deney Salonu)
    // =============================================================
    // EN: Create a 1x1x1 m world volume (Half-length: 0.5 m).
    // TR: 1x1x1 m boyutunda bir dünya hacmi oluþtur (Yarý uzunluk: 0.5 m).
    G4Box* solidWorld = new G4Box("World", 0.5 * m, 0.5 * m, 0.5 * m);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, worldMat, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, true);

    // =============================================================
    // EN: 2. Phantom (Water Tank - Target)
    // TR: 2. Fantom (Su Tanký - Hedef)
    // =============================================================
    // EN: A water box of 20x20x30 cm. The beam enters along the Z-axis.
    // TR: 20x20x30 cm boyutunda su kutusu. Iþýn Z ekseni boyunca girer.
    G4Box* solidPhantom = new G4Box("Phantom", 10 * cm, 10 * cm, 15 * cm); // Z total: 30cm
    G4LogicalVolume* logicPhantom = new G4LogicalVolume(solidPhantom, waterMat, "Phantom");

    // =============================================================
    // EN: *** CRITICAL: STEP LIMITER ***
    // TR: *** KRÝTÝK: ADIM SINIRLAYICI ***
    // =============================================================
    // EN: We limit the maximum step size of particles to 0.5 mm inside the phantom.
    //     This ensures high spatial resolution for the Bragg Peak and prevents
    //     artificial energy accumulation at the entrance due to large steps.
    // TR: Fantom içindeki parçacýklarýn maksimum adým boyutunu 0.5 mm ile sýnýrlandýrýyoruz.
    //     Bu, Bragg Zirvesi için yüksek uzaysal çözünürlük saðlar ve büyük adýmlar
    //     nedeniyle giriþte oluþabilecek yapay enerji birikimini önler.
    logicPhantom->SetUserLimits(new G4UserLimits(0.5 * mm));

    // =============================================================
    // EN: Placement
    // TR: Yerleþtirme
    // =============================================================
    // EN: Place the phantom at the center (0,0,0) of the World.
    // TR: Fantomu Dünyanýn merkezine (0,0,0) yerleþtir.
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logicPhantom, "Phantom", logicWorld, false, 0, true);

    return physWorld;
}