#ifndef ActionInitialization_h
#define ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

// =============================================================
// EN: Action Initialization Class
// TR: Eylem Baþlatma Sýnýfý
// =============================================================
// EN: Registers the user action classes (Run, Generator, Stepping)
//     for both Master and Worker threads in multi-threading mode.
// TR: Çok çekirdekli modda hem Master hem de Worker iþ parçacýklarý için
//     kullanýcý eylem sýnýflarýný (Run, Generator, Stepping) kaydeder.
class ActionInitialization : public G4VUserActionInitialization
{
public:
    ActionInitialization() = default;
    ~ActionInitialization() override = default;

    // EN: Setup for the Master thread (RunAction only).
    // TR: Master iþ parçacýðý için kurulum (Sadece RunAction).
    void BuildForMaster() const override;

    // EN: Setup for Worker threads (All actions).
    // TR: Worker iþ parçacýklarý için kurulum (Tüm eylemler).
    void Build() const override;
};

#endif