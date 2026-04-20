#include "Vehicul.h"
#include <iomanip>

// Implementare constructor
Vehicul::Vehicul(const std::string& numar, const int cap) : nrInmatriculare(numar), capacitateMax(cap), id(++contorId) {
    std::cout << "Vehicul " << nrInmatriculare << " construit.\n";
}

// Implementare destructor
Vehicul::~Vehicul() {
    std::cout << "Vehicul " << nrInmatriculare << " distrus.\n";
}

// Implementare constructor de copiere
Vehicul::Vehicul(const Vehicul& other) : nrInmatriculare(other.nrInmatriculare), capacitateMax(other.capacitateMax), id(++contorId) {}

// Implementare functie swap
void swap(Vehicul& a, Vehicul& b) {
    using std::swap;
    swap(a.nrInmatriculare, b.nrInmatriculare);
    swap(a.capacitateMax, b.capacitateMax);
}

// Implementare operator de atribuire
Vehicul& Vehicul::operator=(const Vehicul& other) {
    if (this == &other)
        return *this;
    nrInmatriculare = other.nrInmatriculare;
    capacitateMax = other.capacitateMax;
    return *this;
}

const std::string Vehicul::getNrInmatriculare() const {
    return nrInmatriculare;
}

std::ostream& operator<<(std::ostream& out, const Vehicul& v) {
    out<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    out<<"(ID " << std::setw(3) << std::setfill('0') << v.id <<") Vehicul inmatriculat: " << v.nrInmatriculare<< '\n';
    out<<"Are capacitate de " << v.capacitateMax << '\n';
    v.afisare(out);
    out<<'\n';
    return out;
}



int Vehicul::contorId = 0;

// int Vehicul::getTotalVehicule() {
//     return contorId;
// }
