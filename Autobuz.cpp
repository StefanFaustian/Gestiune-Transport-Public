#include "Autobuz.h"

void Autobuz::afisare(std::ostream& out) const {
    out<<"Tipul motorului: " << tipMotor << '\n';
}

Autobuz::Autobuz(std::string numar, int cap, std::string motor) : Vehicul(numar,cap), tipMotor(motor) {}

Autobuz::~Autobuz() {
    std::cout<<"Autobuz distrus.\n";
}