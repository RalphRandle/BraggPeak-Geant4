#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4Event;

// =============================================================
// EN: Primary Generator Action Class
// TR: Birincil Üretici Eylem Sýnýfý
// =============================================================
// EN: Controls the generation of primary particles (Protons).
//     Sets energy (150 MeV), position, and direction.
// TR: Birincil parçacýklarýn (Protonlar) üretimini kontrol eder.
//     Enerjiyi (150 MeV), konumu ve yönü ayarlar.
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction() override;

    // EN: Generates particles for each event.
    // TR: Her olay (event) için parçacýk üretir.
    void GeneratePrimaries(G4Event*) override;

private:
    G4ParticleGun* fParticleGun = nullptr;
};

#endif