#include "RunAction.hh"
#include "G4AnalysisManager.hh"

RunAction::RunAction() {
    // =============================================================
    // EN: Initialize Analysis Manager
    // TR: Analiz Yöneticisini Baþlat
    // =============================================================
    // EN: Get the instance of the analysis manager (Singleton pattern).
    // TR: Analiz yöneticisinin örneðini al (Singleton tasarým deseni).
    auto analysisManager = G4AnalysisManager::Instance();

    // EN: Set Default File Type
    // TR: Varsayýlan Dosya Türünü Ayarla
    // =============================================================
    // EN: We use "root" format, which is the standard for High Energy Physics.
    //     (Can be changed to "csv" or "xml" if needed).
    // TR: Yüksek Enerji Fiziði standardý olan "root" formatýný kullanýyoruz.
    //     (Gerekirse "csv" veya "xml" olarak deðiþtirilebilir).
    analysisManager->SetDefaultFileType("root");

    // =============================================================
    // EN: Create Histogram (The Bragg Peak Plot)
    // TR: Histogram Oluþtur (Bragg Zirvesi Grafiði)
    // =============================================================
    // EN: ID: "0" (Reference ID for SteppingAction)
    //     Title: "Energy Deposition vs Z"
    //     Bins: 300 (Dividing 30cm into 1mm bins for high resolution)
    //     Range: -150 mm to +150 mm (Covering the full length of the phantom)
    // TR: ID: "0" (SteppingAction içinde referans verilecek numara)
    //     Baþlýk: "Energy Deposition vs Z"
    //     Kutu Sayýsý (Bins): 300 (Yüksek çözünürlük için 30 cm'yi 1 mm'lik dilimlere böler)
    //     Aralýk: -150 mm ile +150 mm (Fantomun tüm uzunluðunu kapsar)
    analysisManager->CreateH1("0", "Energy Deposition vs Z", 300, -150., 150.);
}

void RunAction::BeginOfRunAction(const G4Run*) {
    // =============================================================
    // EN: Start of Run
    // TR: Koþu (Run) Baþlangýcý
    // =============================================================
    // EN: Open the output file named "BraggOutput".
    //     The extension (.root) is added automatically.
    // TR: "BraggOutput" isminde çýktý dosyasýný aç.
    //     Uzantý (.root) otomatik olarak eklenir.
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->OpenFile("BraggOutput");
}

void RunAction::EndOfRunAction(const G4Run*) {
    // =============================================================
    // EN: End of Run
    // TR: Koþu (Run) Sonu
    // =============================================================
    // EN: IMPORTANT: Write data to disk and close the file.
    //     If this is skipped, the output file will be empty or corrupt.
    // TR: ÖNEMLÝ: Veriyi diske yaz ve dosyayý kapat.
    //     Eðer bu adým atlanýrsa, çýktý dosyasý boþ veya bozuk olur.
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}