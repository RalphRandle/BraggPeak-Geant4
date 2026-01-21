#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"

// =============================================================
// EN: User Stepping Action
// TR: Kullanýcý Adým Eylemi
// =============================================================
// EN: This method is called at every single step of every particle.
//     It is the place where we extract data (scoring).
// TR: Bu metot her parçacýðýn her adýmýnda çaðrýlýr.
//     Veriyi çýkardýðýmýz (skorlama yaptýðýmýz) yer burasýdýr.
void SteppingAction::UserSteppingAction(const G4Step* step) {

    // =============================================================
    // EN: Volume Filter
    // TR: Hacim Filtresi
    // =============================================================
    // EN: We only want to record energy deposited inside the "Phantom" (Water Target).
    //     We ignore steps in the "World" (Air).
    // TR: Sadece "Phantom" (Su Hedef) içinde býrakýlan enerjiyi kaydetmek istiyoruz.
    //     "World" (Hava) içindeki adýmlarý yok sayýyoruz.
    auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
    if (!volume || volume->GetName() != "Phantom") return;

    // =============================================================
    // EN: Energy Deposition Check
    // TR: Enerji Býrakýmý Kontrolü
    // =============================================================
    // EN: Get the energy lost by the particle during this step.
    //     If no energy is lost (e.g., just transportation), we skip.
    // TR: Parçacýðýn bu adýmda kaybettiði enerjiyi al.
    //     Eðer enerji kaybý yoksa (ör. sadece yer deðiþtirme), atla.
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep <= 0.) return;

    // =============================================================
    // EN: Position Retrieval
    // TR: Konum Bilgisi Alma
    // =============================================================
    // EN: We use PreStepPoint to get the position where the step STARTED.
    //     This is standard practice for creating depth-dose profiles.
    // TR: Adýmýn BAÞLADIÐI konumu almak için PreStepPoint kullanýyoruz.
    //     Derinlik-doz profilleri oluþturmak için standart yöntem budur.
    G4double zPos = step->GetPreStepPoint()->GetPosition().z(); // in mm / mm cinsinden

    // =============================================================
    // EN: Fill Histogram
    // TR: Histogramý Doldur
    // =============================================================
    // EN: Send the data to the Analysis Manager.
    //     ID 0: Matches the histogram created in RunAction.
    //     We fill "Z Position" vs "Energy Deposition".
    // TR: Veriyi Analiz Yöneticisine gönder.
    //     ID 0: RunAction'da oluþturulan histogramla eþleþir.
    //     "Z Konumu"na karþýlýk "Enerji Býrakýmý"ný dolduruyoruz.
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillH1(0, zPos, edep);
}