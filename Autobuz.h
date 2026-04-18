#pragma once

#include "Vehicul.h"


class Autobuz : public Vehicul {
    void afisare(std::ostream& out) const override;
    std::string tipMotor;
public:
    Autobuz(std::string numar, int cap, std::string motor);

    ~Autobuz();

};