#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VModularPhysicsList.hh"

// =============================================================
// EN: Physics List Class
// TR: Fizik Listesi Sýnýfý
// =============================================================
// EN: Defines which particles and physical processes are active.
//     Uses G4EmStandardPhysics_option4 for high precision.
// TR: Hangi parçacýklarýn ve fiziksel süreçlerin aktif olduðunu tanýmlar.
//     Yüksek hassasiyet için G4EmStandardPhysics_option4 kullanýr.
class PhysicsList : public G4VModularPhysicsList
{
public:
    PhysicsList();
    ~PhysicsList() override = default;

    // EN: Sets the production cuts for secondary particles.
    // TR: Ýkincil parçacýklar için üretim kesmelerini (cuts) ayarlar.
    void SetCuts() override;
};

#endif