#include "PhysicsList.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4StepLimiterPhysics.hh"

PhysicsList::PhysicsList() : G4VModularPhysicsList() {

    // =============================================================
    // EN: Electromagnetic Physics Model
    // TR: Elektromanyetik Fizik Modeli
    // =============================================================
    // EN: We use "Option4" (EMZ), which is the most accurate standard physics list 
    //     provided by Geant4 for medical physics and low-energy applications.
    //     It provides the best precision for Bragg Peak and stopping power calculations.
    // TR: Medikal fizik ve düþük enerji uygulamalarý için Geant4'ün sunduðu 
    //     en hassas standart fizik listesi olan "Option4"ü (EMZ) kullanýyoruz.
    //     Bragg Zirvesi ve durdurma gücü hesaplamalarý için en iyi hassasiyeti saðlar.
    RegisterPhysics(new G4EmStandardPhysics_option4());

    // =============================================================
    // EN: Step Limiter Support
    // TR: Adým Sýnýrlayýcý Desteði
    // =============================================================
    // EN: This physics module is REQUIRED to make 'G4UserLimits' work.
    //     Without registering this, the 0.5 mm limit in DetectorConstruction would be ignored.
    // TR: Bu fizik modülü, 'G4UserLimits' komutunun çalýþmasý için ZORUNLUDUR.
    //     Bunu kaydetmezsek, DetectorConstruction'daki 0.5 mm sýnýrý görmezden gelinir.
    RegisterPhysics(new G4StepLimiterPhysics());
}

void PhysicsList::SetCuts() {
    // =============================================================
    // EN: Production Cuts
    // TR: Üretim Kesmeleri
    // =============================================================
    // EN: Set default cut values for secondary particle production (gamma, e-, e+).
    // TR: Ýkincil parçacýk üretimi (gama, elektron, pozitron) için varsayýlan kesme deðerlerini ayarla.
    SetCutsWithDefault();
}