#include "Tramvai.h"
#include "Exceptii.h"
#include <regex>

void Tramvai::afisare(std::ostream& out) const {
    out << " | [TRAMVAI] Nr. vagoane: " << nrVagoane << '\n';
}

Tramvai::Tramvai(const std::string numar, const int cap, const int vagoane, const int km) : Vehicul(numar,cap,km), nrVagoane(vagoane) {
    const std::regex regexTramvai("^[A-Z]{1,2}[0-9]{4}$");
    if (!std::regex_match(numar, regexTramvai)) {
        throw EroareValidareVehicul("Numar invalid pentru tramvai (" + numar + "). Format asteptat: B1234.");
    }
    if (vagoane > MAX_VAGOANE)
        throw EroareValidareVehicul("Tramvaiul " + nrInmatriculare + " nu poate avea un numar negativ de vagoane sau un numar mai mare decat " + std::to_string(MAX_VAGOANE) + " de vagoane.");
}

Tramvai::Tramvai(const Tramvai& other) : Vehicul(other), nrVagoane(other.nrVagoane) {}

Tramvai& Tramvai::operator=(Tramvai other) {
    swap(*this,other);
    return *this;
}

Tramvai* Tramvai::clone() const { return new Tramvai(*this); }

void swap(Tramvai& a, Tramvai& b) noexcept {
    using std::swap;
    swap(static_cast<Vehicul&>(a),static_cast<Vehicul&>(b));
    swap(a.nrVagoane,b.nrVagoane);
}

bool Tramvai::necesitaRevizie() const { return (nrKM - nrKmUltimaRevizie) > 3500; }

Tramvai::~Tramvai() {
    //std::cout<<"Tramvai distrus.\n";
}

//int Tramvai::MAX_VAGOANE = 4;


