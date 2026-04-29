#include "Troleibuz.h"
#include "Exceptii.h"
#include <regex>

void Troleibuz::afisare(std::ostream& out) const {

    out << " | [TROLEIBUZ] Baterie aux: " << (baterieAuxiliara ? "Da" : "Nu") << '\n';
}

Troleibuz::Troleibuz(const std::string& numar, const int cap, const bool baterie, const int km) : Vehicul(numar,cap,km), baterieAuxiliara(baterie) {
    const std::regex regexTroleibuz("^[A-Z]{1,2}[0-9]{4}$");
    if (!std::regex_match(numar, regexTroleibuz)) {
        throw EroareValidareVehicul("Numar invalid pentru tramvai (" + numar + "). Format asteptat: B1234.");
    }

}

Troleibuz::Troleibuz(const Troleibuz& other) : Vehicul(other), baterieAuxiliara(other.baterieAuxiliara) {}

Troleibuz& Troleibuz::operator=(Troleibuz other) {
    swap(*this,other);
    return *this;
}

Troleibuz* Troleibuz::clone() const { return new Troleibuz(*this); }

void swap(Troleibuz& a, Troleibuz& b) noexcept{
    using std::swap;
    swap(static_cast<Vehicul&>(a),static_cast<Vehicul&>(b));
    swap(a.baterieAuxiliara,b.baterieAuxiliara);
}

bool Troleibuz::necesitaRevizie() const {
    if (baterieAuxiliara) return (nrKM - nrKmUltimaRevizie) > 1800;
    return (nrKM - nrKmUltimaRevizie > 2000);
}

Troleibuz::~Troleibuz() = default; // { std::cout << "Troleibuz distrus.\n"; }
