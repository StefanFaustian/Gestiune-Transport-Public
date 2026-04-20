#pragma once

#include "Vehicul.h"
#include <vector>
#include <memory>

class Depou {
    std::string nume;
    std::vector<std::unique_ptr<Vehicul>> vehicule;
public:
    Depou(const std::string& nume_);

    ~Depou();
    void adaugaVehicul(Vehicul* v);
    void inspectieDeRutina() const;
    friend std::ostream& operator<<(std::ostream& out, const Depou& d);
};