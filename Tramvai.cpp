#include "Tramvai.h"

#include "Autobuz.h"

void Tramvai::afisare(std::ostream& out) const {
    out << "Nr. vagoane: " << nrVagoane << '\n';
}

Tramvai::Tramvai(std::string numar, int cap, int vagoane) : Vehicul(numar,cap), nrVagoane(vagoane) {}

Tramvai::Tramvai(const Tramvai& other) : Vehicul(other), nrVagoane(other.nrVagoane) {}

Tramvai& Tramvai::operator=(Tramvai other) {
    swap(*this,other);
    return *this;
}

void swap(Tramvai& a, Tramvai& b) {
    using std::swap;
    swap(static_cast<Vehicul&>(a),static_cast<Vehicul&>(b));
    swap(a.nrVagoane,b.nrVagoane);
}

Tramvai::~Tramvai() {
    std::cout<<"Tramvai distrus.\n";
}


