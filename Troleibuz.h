#pragma once

#include "Vehicul.h"

class Troleibuz : public Vehicul {
    void afisare(std::ostream& out) const override;
    bool baterieAuxiliara;
public:
    Troleibuz(std::string numar, int cap, bool baterie);
    
    ~Troleibuz();
    
};