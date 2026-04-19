#pragma once

#include "Vehicul.h"

class Tramvai : public Vehicul {
    void afisare(std::ostream& out) const override;
    int nrVagoane;
public:
    Tramvai(std::string numar, int cap, int vagoane);

    // Constructor de copiere
    Tramvai(const Tramvai& other);

    // Operatorul =
    Tramvai& operator=(Tramvai other);

    // Functie prieten swap
    friend void swap(Tramvai& a, Tramvai& b);

    ~Tramvai();
};