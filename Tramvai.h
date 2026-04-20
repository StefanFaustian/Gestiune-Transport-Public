#pragma once

#include "Vehicul.h"

class Tramvai : public Vehicul {
    void afisare(std::ostream& out) const override;
    int nrVagoane;
public:
    Tramvai(const std::string numar, const int cap, const int vagoane);

    // Constructor de copiere
    Tramvai(const Tramvai& other);

    // Operatorul =
    Tramvai& operator=(Tramvai other);

    // Functie prieten swap
    friend void swap(Tramvai& a, Tramvai& b);

    ~Tramvai();
};