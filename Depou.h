#pragma once

#include "Vehicul.h"
#include <vector>
#include <memory>

class Depou {
    static int contorId;
    const int id;
    int capacitateMax;
    std::string nume;
    std::vector<std::shared_ptr<Vehicul>> vehicule;
public:
    // Constructor
    Depou(const std::string& nume_, int cap);

    // Constructor de copiere
    Depou(const Depou& other);

    // Constructor de mutare
    Depou(Depou&& other) noexcept;

    // Operatorul =
    Depou& operator=(Depou other);

    ~Depou();
    void adaugaVehicul(std::shared_ptr<Vehicul> v);
    void inspectieDeRutina() const;
    friend std::ostream& operator<<(std::ostream& out, const Depou& d);
    friend void swap(Depou& a, Depou& b);
};