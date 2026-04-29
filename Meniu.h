#pragma once
#include "Manager.h"
#include <string>

class Meniu {
    Manager& manager;
    void afiseazaOptiuni() const;
    std::string alegeVehiculDinDepou() const;
    std::string alegeLinie() const;
    void trateazaAdaugareVehicul();
    void trateazaTrimitereInService();

public:
    explicit Meniu(Manager& m);
    void start();
};