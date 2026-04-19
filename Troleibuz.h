#pragma once

#include "Vehicul.h"

class Troleibuz : public Vehicul {
    void afisare(std::ostream& out) const override;
    bool baterieAuxiliara;
public:
    // Constructor
    Troleibuz(std::string numar, int cap, bool baterie);

    // Constructor de copiere
    Troleibuz(Troleibuz& other);

    // Operator =
    Troleibuz& operator=(Troleibuz& other);

    // Functia prietena swap
    friend void swap(Troleibuz& a, Troleibuz& b);

    ~Troleibuz();
    
};