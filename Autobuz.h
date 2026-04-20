#pragma once

#include "Vehicul.h"


class Autobuz : public Vehicul {
    void afisare(std::ostream& out) const override;
    std::string tipMotor;
public:
    // Constructor
    Autobuz(const std::string& numar, const int cap, const std::string& motor);

    // Constructor de copiere
    Autobuz(const Autobuz& other);

    // Operatorul =
    Autobuz& operator=(const Autobuz other);

    // Functie prieten swap
    friend void swap(Autobuz& a, Autobuz& b);

    // Destructor
    ~Autobuz();

};