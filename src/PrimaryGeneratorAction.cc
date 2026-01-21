#include "PrimaryGeneratorAction.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() {
    // =============================================================
    // EN: Initialize Particle Gun
    // TR: Parçacýk Tabancasýný Baþlat
    // =============================================================
    // EN: Create a gun that fires 1 particle per event.
    // TR: Her olayda (event) 1 parçacýk ateþleyen bir tabanca oluþtur.
    fParticleGun = new G4ParticleGun(1);

    // =============================================================
    // EN: Particle Definition
    // TR: Parçacýk Tanýmý
    // =============================================================
    // EN: Find the "proton" definition in Geant4 particle table.
    // TR: Geant4 parçacýk tablosunda "proton" tanýmýný bul.
    G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("proton");
    fParticleGun->SetParticleDefinition(particle);

    // =============================================================
    // EN: Beam Properties (The Bragg Peak Physics)
    // TR: Iþýn Özellikleri (Bragg Zirvesi Fiziði)
    // =============================================================
    // EN: Energy: 150 MeV. 
    //     Theoretical range in water is approx 15.8 cm.
    // TR: Enerji: 150 MeV. 
    //     Sudaki teorik menzili yaklaþýk 15.8 cm'dir.
    fParticleGun->SetParticleEnergy(150. * MeV);

    // EN: Direction: Along the Z-axis (0, 0, 1).
    // TR: Yön: Z ekseni boyunca (0, 0, 1).
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));

    // EN: Position: -20 cm on Z-axis.
    //     We start OUTSIDE the phantom (which starts at -15 cm) to observe the entrance dose.
    // TR: Konum: Z ekseninde -20 cm.
    //     Giriþ dozunu gözlemlemek için (-15 cm'de baþlayan) fantomun DIÞINDAN baþlýyoruz.
    fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., -20. * cm));
}

// =============================================================
// EN: Destructor
// TR: Yýkýcý Fonksiyon
// =============================================================
PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    // EN: Clean up memory to prevent leaks.
    // TR: Sýzýntýlarý önlemek için belleði temizle.
    delete fParticleGun;
}

// =============================================================
// EN: Generation Loop
// TR: Üretim Döngüsü
// =============================================================
void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    // EN: Trigger the gun to generate the vertex for this event.
    // TR: Bu olay için verteksi (etkileþim noktasýný) oluþturmak üzere tabancayý tetikle.
    fParticleGun->GeneratePrimaryVertex(anEvent);
}