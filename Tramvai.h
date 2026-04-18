#pragma once

#include "Vehicul.h"

class Tramvai : public Vehicul {
    void afisare(std::ostream& out) const override;
    int nrVagoane;
public:
    Tramvai(std::string numar, int cap, int vagoane);

    ~Tramvai();
};