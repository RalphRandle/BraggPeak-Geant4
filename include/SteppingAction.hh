#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

// =============================================================
// EN: Stepping Action Class
// TR: Adým Eylem Sýnýfý
// =============================================================
// EN: Called at every step of the simulation.
//     Used to extract energy deposition data from the Phantom.
// TR: Simülasyonun her adýmýnda çaðrýlýr.
//     Fantom içindeki enerji birikim verisini çekmek için kullanýlýr.
class SteppingAction : public G4UserSteppingAction
{
public:
    SteppingAction() = default;
    ~SteppingAction() override = default;

    // EN: Main method to collect data from steps.
    // TR: Adýmlardan veri toplamak için ana metot.
    void UserSteppingAction(const G4Step*) override;
};

#endif