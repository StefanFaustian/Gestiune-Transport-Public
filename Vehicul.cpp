#include "Vehicul.h"
#include "Exceptii.h"
#include <iomanip>

Vehicul::Vehicul() : id(++contorId) {}

// Implementare constructor
Vehicul::Vehicul(const std::string& numar, const int cap) : id(++contorId), capacitateMax(cap), nrInmatriculare(numar) {
    if (cap <= 0) {
        throw EroareValidareVehicul("Capacitatea vehiculului nu poate fi negativa sau nula.");
    }

    std::cout << "Vehicul " << nrInmatriculare << " construit.\n";
}

// Implementare destructor
Vehicul::~Vehicul() {
    std::cout << "Vehicul " << nrInmatriculare << " distrus.\n";
}

Vehicul::Vehicul(Vehicul&& other) noexcept
    : id(other.id),
      capacitateMax(other.capacitateMax),
      nrInmatriculare(std::move(other.nrInmatriculare)) // se muta string-ul
{
    other.capacitateMax = 0;
}

// Implementare constructor de copiere
Vehicul::Vehicul(const Vehicul& other) : id(++contorId), capacitateMax(other.capacitateMax), nrInmatriculare(other.nrInmatriculare) {}

// Implementare functie swap
void swap(Vehicul& a, Vehicul& b) noexcept {
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
