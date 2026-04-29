#include "Autobuz.h"
#include "Exceptii.h"
#include <regex>

void Autobuz::afisare(std::ostream& out) const {
    out<<"Tipul motorului: " << tipMotor << "\n~~~~~~~~~~~AUTOBUZ~~~~~~~~~~~\n";
}

Autobuz::Autobuz() {}

Autobuz::Autobuz(const std::string& numar, const int cap, const std::string& motor, const int km) : Vehicul(numar,cap,km), tipMotor(motor) {
    const std::regex regexAutobuz("^[A-Z]{1,2}[0-9]{2,3}[A-Z]{3}$");
    if (!std::regex_match(numar, regexAutobuz)) {
        throw EroareValidareVehicul("Numar invalid pentru autobuz (" + numar + "). Format asteptat: B123XYZ.");
    }
}

Autobuz::Autobuz(const Autobuz& other) : Vehicul(other), tipMotor(other.tipMotor) {}

Autobuz& Autobuz::operator=(Autobuz other) {
    swap(*this,other);
    return *this;
}

void swap(Autobuz& a, Autobuz& b) noexcept {
    using std::swap;
    // swap(a.nrInmatriculare,b.nrInmatriculare);
    // swap(a.capacitateMax,b.capacitateMax);
    swap(static_cast<Vehicul&>(a),static_cast<Vehicul&>(b));
    swap(a.tipMotor,b.tipMotor);
}

Autobuz* Autobuz::clone() const { return new Autobuz(*this); }

Autobuz::~Autobuz() {
    std::cout<<"Autobuz distrus.\n";
}
