#pragma once

#include <string>
#include <iostream>

class Vehicul {
    static int contorId;
    virtual void afisare(std::ostream&) const = 0;
protected:
    std::string nrInmatriculare;
    int capacitateMax;
    const int id;

public:
    // Constructor
    Vehicul(const std::string& numar, int cap);

    // Copy Constructor
    Vehicul(const Vehicul& other);

    // Operator de atribuire (folosind copy-and-swap)
    Vehicul& operator=(const Vehicul& other);

    // Destructor
    virtual ~Vehicul();

    // "Constructor virtual" - pattern-ul CLONE
    //virtual Vehicul* clone() const = 0;

    // Funcție statică
    //static int getTotalVehicule();

    // Prieten pentru a implementa copy-and-swap
    //friend void swap(Vehicul& first, Vehicul& second);

    //
    friend std::ostream& operator<<(std::ostream& out, const Vehicul& v);
};