#include "Tramvai.h"

#include "Autobuz.h"

void Tramvai::afisare(std::ostream& out) const {
    out << "Nr. vagoane: " << nrVagoane << '\n';
}

Tramvai::Tramvai(std::string numar, int cap, int vagoane) : Vehicul(numar,cap), nrVagoane(vagoane) {}

Tramvai::~Tramvai() {
    std::cout<<"Tramvai distrus.\n";
}


