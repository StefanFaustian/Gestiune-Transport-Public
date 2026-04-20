#include "Troleibuz.h"

void Troleibuz::afisare(std::ostream& out) const {
    if (baterieAuxiliara) out << "Are baterie auxiliara.";
    else out << "Nu are baterie auxiliara.";
    out<<"\n~~~~~~~~~~~TROLEIBUZ~~~~~~~~~~~\n";
}

Troleibuz::Troleibuz(const std::string& numar, const int cap, const bool baterie) : Vehicul(numar,cap), baterieAuxiliara(baterie) {}

Troleibuz::Troleibuz(Troleibuz& other) : Vehicul(other), baterieAuxiliara(other.baterieAuxiliara) {}

Troleibuz& Troleibuz::operator=(Troleibuz& other) {
    swap(*this,other);
    return *this;
}

void swap(Troleibuz& a, Troleibuz& b) {
    using std::swap;
    swap(static_cast<Vehicul&>(a),static_cast<Vehicul&>(b));
    swap(a.baterieAuxiliara,b.baterieAuxiliara);
}

Troleibuz::~Troleibuz() {
    std::cout << "Troleibuz distrus.\n";
}
