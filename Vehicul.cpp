#include "Vehicul.h"
#include "Exceptii.h"
#include <iomanip>

Vehicul::Vehicul() : id(++contorId) {}

// Implementare constructor
Vehicul::Vehicul(const std::string& numar, const int cap, const int km) : id(++contorId), capacitateMax(cap), nrKM(km), nrInmatriculare(numar) {
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
      nrKM(other.nrKM),
      nrInmatriculare(std::move(other.nrInmatriculare)) // se muta string-ul
{
    other.capacitateMax = 0;
}

// Implementare constructor de copiere
Vehicul::Vehicul(const Vehicul& other) : id(++contorId), capacitateMax(other.capacitateMax), nrKM(other.nrKM), nrInmatriculare(other.nrInmatriculare) {}

// Implementare functie swap
void swap(Vehicul& a, Vehicul& b) noexcept {
    using std::swap;
    swap(a.nrKM, b.nrKM);
    swap(a.nrInmatriculare, b.nrInmatriculare);
    swap(a.capacitateMax, b.capacitateMax);
}

// Implementare operator de atribuire
Vehicul& Vehicul::operator=(const Vehicul& other) {
    if (this == &other)
        return *this;
    nrKM = other.nrKM;
    nrInmatriculare = other.nrInmatriculare;
    capacitateMax = other.capacitateMax;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vehicul& v) {
    out<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    out<<"(ID " << std::setw(3) << std::setfill('0') << v.id <<") Vehicul inmatriculat: " << v.nrInmatriculare<< '\n';
    out<<"Are capacitate de " << v.capacitateMax << '\n';
    out<<"Km parcursi: " << v.nrKM << '\n';
    v.afisare(out);
    out<<'\n';
    return out;
}



int Vehicul::contorId = 0;

// int Vehicul::getTotalVehicule() {
//     return contorId;
// }
