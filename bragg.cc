#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInitialization.hh"

// =============================================================
// EN: Main Function
// TR: Ana Fonksiyon
// =============================================================
int main(int argc, char** argv) {

    // =============================================================
    // EN: 1. Run Manager Setup
    // TR: 1. Run Manager Kurulumu
    // =============================================================
    // EN: Construct the default Run Manager. It controls the entire simulation flow.
    // TR: Varsayýlan Run Manager'ý oluþtur. Tüm simülasyon akýþýný bu kontrol eder.
    auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

    // =============================================================
    // EN: 2. Mandatory Initialization Classes
    // TR: 2. Zorunlu Baþlatma Sýnýflarý
    // =============================================================
    // EN: Set the Geometry (Water Phantom & World).
    // TR: Geometriyi ayarla (Su Fantomu ve Dünya).
    runManager->SetUserInitialization(new DetectorConstruction());

    // EN: Set the Physics List (EM Option4 + Step Limiter).
    // TR: Fizik Listesini ayarla (EM Seçenek 4 + Adým Sýnýrlayýcý).
    runManager->SetUserInitialization(new PhysicsList());

    // EN: Set User Actions (Primary Generator, Run Action, Stepping Action).
    // TR: Kullanýcý Eylemlerini ayarla (Parçacýk Kaynaðý, Run ve Stepping iþlemleri).
    runManager->SetUserInitialization(new ActionInitialization());

    // =============================================================
    // EN: 3. Visualization Manager
    // TR: 3. Görselleþtirme Yöneticisi
    // =============================================================
    // EN: Initialize visualization to see the geometry and tracks (OpenGL, etc.).
    // TR: Geometriyi ve izleri görmek için görselleþtirmeyi baþlat (OpenGL vb.).
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    // EN: Get the pointer to the User Interface manager.
    // TR: Kullanýcý Arayüzü yöneticisinin iþaretçisini al.
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    // =============================================================
    // EN: 4. Mode Selection (Interactive vs Batch)
    // TR: 4. Mod Seçimi (Etkileþimli veya Toplu Ýþlem)
    // =============================================================
    if (argc == 1) {
        // EN: Interactive mode (with GUI window).
        // TR: Etkileþimli mod (Arayüz penceresi ile).
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);

        // EN: Execute the visualization macro setup.
        // TR: Görselleþtirme makro ayarlarýný çalýþtýr.
        UImanager->ApplyCommand("/control/execute vis.mac");

        ui->SessionStart();
        delete ui;
    }
    else {
        // EN: Batch mode (No GUI, mostly for heavy calculations).
        // TR: Toplu iþlem modu (Arayüzsüz, genellikle aðýr hesaplamalar için).
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    }

    // =============================================================
    // EN: 5. Cleanup
    // TR: 5. Temizlik
    // =============================================================
    delete visManager;
    delete runManager;
}