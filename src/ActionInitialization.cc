#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"

// =============================================================
// EN: Master Thread Setup
// TR: Ana (Master) Ýþ Parçacýðý Kurulumu
// =============================================================
// EN: In multi-threaded mode, this method runs only on the master thread.
//     Its job is to merge results (histograms) from worker threads.
// TR: Çok çekirdekli (multi-threaded) modda bu metot sadece ana (master) thread üzerinde çalýþýr.
//     Görevi, iþçi thread'lerden gelen sonuçlarý (histogramlarý) birleþtirmektir.
void ActionInitialization::BuildForMaster() const {
    SetUserAction(new RunAction);
}

// =============================================================
// EN: Worker Thread Setup
// TR: Ýþçi (Worker) Ýþ Parçacýðý Kurulumu
// =============================================================
// EN: This method runs for every worker thread (or the single thread in sequential mode).
//     It sets up the simulation flow for generating and tracking particles.
// TR: Bu metot her iþçi thread için (veya sýralý modda tek thread için) çalýþýr.
//     Parçacýk üretimi ve takibi için simülasyon akýþýný kurar.
void ActionInitialization::Build() const {

    // EN: 1. Particle Generator: Defines what to shoot (Protons, 150 MeV, etc.).
    // TR: 1. Parçacýk Kaynaðý: Neyi ateþleyeceðini (Proton, 150 MeV vb.) tanýmlar.
    SetUserAction(new PrimaryGeneratorAction);

    // EN: 2. Run Action: Handles file opening/closing (ROOT/CSV) and histogram creation.
    // TR: 2. Run Ýþlemi: Dosya açma/kapama (ROOT/CSV) ve histogram oluþturma iþlerini yapar.
    SetUserAction(new RunAction);

    // EN: 3. Stepping Action: Records data (energy deposition) step by step.
    // TR: 3. Adým Ýþlemi: Verileri (enerji birikimini) adým adým kaydeder.
    SetUserAction(new SteppingAction);
}