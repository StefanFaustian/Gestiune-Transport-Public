#include "Autobuz.h"

void Autobuz::afisare(std::ostream& out) const {
    out<<"Tipul motorului: " << tipMotor << "\n~~~~~~~~~~~AUTOBUZ~~~~~~~~~~~\n";
}

Autobuz::Autobuz(const std::string& numar, const int cap, const std::string& motor) : Vehicul(numar,cap), tipMotor(motor) {}

Autobuz::Autobuz(const Autobuz& other) : Vehicul(other), tipMotor(other.tipMotor) {}

Autobuz& Autobuz::operator=(Autobuz other) {
    swap(*this,other);
    return *this;
}

void swap(Autobuz& a, Autobuz& b) {
    using std::swap;
    // swap(a.nrInmatriculare,b.nrInmatriculare);
    // swap(a.capacitateMax,b.capacitateMax);
    swap(static_cast<Vehicul&>(a),static_cast<Vehicul&>(b));
    swap(a.tipMotor,b.tipMotor);
}

Autobuz::~Autobuz() {
    std::cout<<"Autobuz distrus.\n";
}
