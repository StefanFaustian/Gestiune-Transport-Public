#pragma once

#include "Vehicul.h"


class Autobuz : public Vehicul {
    void afisare(std::ostream& out) const override;
    std::string tipMotor;
public:

    Autobuz();
    // Constructor
    Autobuz(const std::string& numar, int cap, const std::string& motor, int km = 0);

    // Constructor de copiere
    Autobuz(const Autobuz& other);

    Autobuz* clone() const override;

    // Operatorul =
    Autobuz& operator=(Autobuz other);

    // Functie prieten swap
    friend void swap(Autobuz& a, Autobuz& b) noexcept;

    // Destructor
    ~Autobuz() override;

};