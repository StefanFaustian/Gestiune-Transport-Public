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

    // Constructor de copiere
    Vehicul(const Vehicul& other);

    // Operator de atribuire
    Vehicul& operator=(const Vehicul& other);

    // Destructor
    virtual ~Vehicul();

    // Funcție statica
    // static int getTotalVehicule();

    // Afisare
    friend std::ostream& operator<<(std::ostream& out, const Vehicul& v);

    friend void swap(Vehicul& a, Vehicul& b);
};