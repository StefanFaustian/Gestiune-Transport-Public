#pragma once

#include "Vehicul.h"
#include <vector>
#include <unordered_set>

enum class TipVehiculLinie {
    AUTOBUZ,
    TRAMVAI,
    TROLEIBUZ
};

std::ostream& operator<<(std::ostream& out, TipVehiculLinie tip);

struct Statie {
    std::string nume;
    int distPrecedent; // numarul de km de la statia curenta pana la statia anterioara
};

class Linie {
    std::string indicativ;
    TipVehiculLinie tipVehicul;
    std::vector<Statie> statii;
    std::unordered_set<std::string> vehiculePeTraseu;
    static std::unordered_set<std::string> vehiculeActivePeLinii;
public:
    Linie(const std::string& indicativ_,TipVehiculLinie tip);
    void adaugaStatie(const std::string& numeStatie, int distanta);
    void eliminaStatie(const std::string& nume);
    int calculeazaDistantaTurRetur() const;

    // Metode pentru flota pe traseu
    void trimiteVehicul(const std::string& nrInmatriculare);
    void retrageVehicul(const std::string& nrInmatriculare);
    void retrageToataFlota();

    // Getters
    const std::string& getIndicativ() const { return indicativ; }
    const std::unordered_set<std::string>& getVehiculePeTraseu() const { return vehiculePeTraseu; }
    TipVehiculLinie getTipVehicul() const { return tipVehicul; }

    static bool esteVehiculActiv(const std::string& nrInmatriculare) { return vehiculeActivePeLinii.count(nrInmatriculare);}
    friend std::ostream& operator<<(std::ostream& out, const Linie& linie);

    ~Linie() = default;
};