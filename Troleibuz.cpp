#include "Troleibuz.h"

void Troleibuz::afisare(std::ostream& out) const {
    if (baterieAuxiliara) std::cout << "Are baterie auxiliara.\n";
    else std::cout << "Nu are baterie auxiliara.\n";
}

Troleibuz::Troleibuz(std::string numar, int cap, bool baterie) : Vehicul(numar,cap), baterieAuxiliara(baterie) {}

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
