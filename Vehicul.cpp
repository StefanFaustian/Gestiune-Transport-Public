#include "Vehicul.h"
#include "Exceptii.h"
#include <iomanip>

Vehicul::Vehicul() : id(++contorId) {}

// Implementare constructor
Vehicul::Vehicul(const std::string& numar, const int cap, const int km) : id(++contorId), capacitateMax(cap), nrKM(km), nrKmUltimaRevizie(km), nrInmatriculare(numar) {
    if (cap <= 0) {
        throw EroareValidareVehicul("Capacitatea vehiculului nu poate fi negativa sau nula.");
    }

    //std::cout << "Vehicul " << nrInmatriculare << " construit.\n";
}

// Implementare destructor
Vehicul::~Vehicul() {
    //std::cout << "Vehicul " << nrInmatriculare << " distrus.\n";
}

Vehicul::Vehicul(Vehicul&& other) noexcept
    : id(other.id),
      capacitateMax(other.capacitateMax),
      nrKM(other.nrKM),
      nrKmUltimaRevizie(other.nrKmUltimaRevizie),
      nrInmatriculare(std::move(other.nrInmatriculare)) // se muta string-ul
{
    other.capacitateMax = 0;
}

// Implementare constructor de copiere
Vehicul::Vehicul(const Vehicul& other) : id(++contorId), capacitateMax(other.capacitateMax), nrKM(other.nrKM), nrKmUltimaRevizie(other.nrKmUltimaRevizie), nrInmatriculare(other.nrInmatriculare) {}

// Implementare functie swap
void swap(Vehicul& a, Vehicul& b) noexcept {
    using std::swap;
    swap(a.nrKM, b.nrKM);
    swap(a.nrKmUltimaRevizie,b.nrKmUltimaRevizie);
    swap(a.nrInmatriculare, b.nrInmatriculare);
    swap(a.capacitateMax, b.capacitateMax);
}

// Implementare operator de atribuire
Vehicul& Vehicul::operator=(const Vehicul& other) {
    if (this == &other)
        return *this;
    nrKM = other.nrKM;
    nrKmUltimaRevizie = other.nrKmUltimaRevizie;
    nrInmatriculare = other.nrInmatriculare;
    capacitateMax = other.capacitateMax;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vehicul& v) {
    out << "[ID: " << std::setfill('0') << std::setw(3) << v.id << "] "
        << std::setfill(' ') << std::left << std::setw(7) << v.nrInmatriculare
        << std::right
        << " | Cap: " << v.capacitateMax
        << " | KM: " << v.nrKM;

    v.afisare(out);

    return out;
}

int Vehicul::contorId = 0;
