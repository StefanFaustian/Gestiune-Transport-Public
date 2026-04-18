#include "Troleibuz.h"

void Troleibuz::afisare(std::ostream& out) const {
    if (baterieAuxiliara) std::cout << "Are baterie auxiliara.\n";
    else std::cout << "Nu are baterie auxiliara.\n";
}

Troleibuz::Troleibuz(std::string numar, int cap, bool baterie) : Vehicul(numar,cap), baterieAuxiliara(baterie) {}

Troleibuz::~Troleibuz() {
    std::cout << "Troleibuz distrus.\n";
}
