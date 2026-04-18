#include "Vehicul.h"
#include <iomanip>

// Implementare constructor
Vehicul::Vehicul(const std::string& numar, int cap) : nrInmatriculare(numar), capacitateMax(cap), id(++contorId) {
    std::cout << "Vehicul " << nrInmatriculare << " construit.\n";
}

// Implementare destructor
Vehicul::~Vehicul() {
    std::cout << "Vehicul " << nrInmatriculare << " distrus.\n";
}

// Implementare constructor de copiere
Vehicul::Vehicul(const Vehicul& other) : nrInmatriculare(other.nrInmatriculare), capacitateMax(other.capacitateMax), id(++contorId) {}

// Implementare functie swap
// void swap(Vehicul& crt, Vehicul& other) {
//     using std::swap;
//     swap(crt.nrInmatriculare, other.nrInmatriculare);
//     swap(crt.capacitateMax, other.capacitateMax);
// }

// Implementare operator de atribuire
Vehicul& Vehicul::operator=(const Vehicul& other) {
    if (this == &other)
        return *this;
    nrInmatriculare = other.nrInmatriculare;
    capacitateMax = other.capacitateMax;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vehicul& v) {
    out<<"(ID " << std::setw(3) << std::setfill('0') << v.id <<") Vehicul inmatriculat: " << v.nrInmatriculare<< '\n';
    out<<"Are capacitate de " << v.capacitateMax << '\n';
    v.afisare(out);
    out<<'\n';
    return out;
}

int Vehicul::contorId = 0;

//void Vehicul::afisare(std::ostream& out) const {}
