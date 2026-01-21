#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;

// =============================================================
// EN: Run Action Class
// TR: Koþu (Run) Eylem Sýnýfý
// =============================================================
// EN: Manages the start and end of a run.
//     Handles output file creation (ROOT) and histogram booking.
// TR: Bir koþunun (run) baþlangýcýný ve bitiþini yönetir.
//     Çýktý dosyasý oluþturmayý (ROOT) ve histogram kaydýný halleder.
class RunAction : public G4UserRunAction
{
public:
    RunAction();
    ~RunAction() override = default;

    // EN: Called before the run starts (Open file).
    // TR: Koþu baþlamadan önce çaðrýlýr (Dosyayý aç).
    void BeginOfRunAction(const G4Run*) override;

    // EN: Called after the run ends (Write & Close file).
    // TR: Koþu bittikten sonra çaðrýlýr (Yaz & Dosyayý kapat).
    void EndOfRunAction(const G4Run*) override;
};

#endif