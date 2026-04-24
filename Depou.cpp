#include "Depou.h"
#include "Autobuz.h"
#include "Tramvai.h"
#include "Troleibuz.h"
#include "Exceptii.h"
#include <random>

Depou::Depou(const std::string& nume_, const int cap) : id(++contorId), capacitateMax(cap), nume(nume_) {
    if (nume_.empty()) {
        throw EroareValidareDepou("Un depou trebuie sa aiba un nume.");
    }
}

Depou::Depou(const Depou& other) : id(++contorId), capacitateMax(other.capacitateMax), nume(other.nume) {
    for (const auto& vehicul : other.vehicule) {
        std::shared_ptr<Vehicul> copieVehicul(vehicul->clone());
        this->adaugaVehicul(copieVehicul);
    }
}

Depou::Depou(Depou&& other) noexcept
    : id(other.id),
      capacitateMax(other.capacitateMax),
      nume(std::move(other.nume)),
      vehicule(std::move(other.vehicule)) // se muta vectorul de shared_ptr, operatie de complexitate O(1), cu mult mai rapid decat CC!
{
    other.capacitateMax = 0;
}

Depou& Depou::operator=(Depou other) {
    swap(*this, other);
    return *this;
}

Depou::~Depou() = default;

void Depou::adaugaVehicul(const std::shared_ptr<Vehicul> v) {
    if (vehicule.size() >= static_cast<size_t>(capacitateMax)) {
        throw EroareCapacitateDepou(nume);
    }
    vehicule.emplace_back(v);
}

void Depou::inspectieDeRutina() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> proc(1, 100);
    std::cout << "--------- Inspectie de rutina la Depoul " << nume << " ---------\n\n";
    for (const auto& vehicul : vehicule) {
        std::cout << "\n/// Vehicul inmatriculat " << vehicul->getNrInmatriculare() << " ///\n";
        const int stareFrane = proc(gen), stareUsi = proc(gen), stareIluminat = proc(gen);
        std::cout << "Verificare frane ............... " << (stareFrane > 25 ? "OK\n" : "Necesita mentenanta!\n");
        std::cout << "Verificare usi ................. " << (stareUsi > 25 ? "OK\n" : "Necesita mentenanta!\n");
        std::cout << "Verificare iluminat ............ " << (stareIluminat > 25 ? "OK\n" : "Necesita mentenanta!\n");
        if (dynamic_cast<const Autobuz*>(vehicul.get())) {
            const int stareMotor = proc(gen), starePneuri = proc(gen);
            std::cout << "Verificare motor ............... " << (stareMotor > 25 ? "OK\n" : "Necesita mentenanta!\n");
            std::cout << "Verificare pneuri .............. " << (starePneuri > 25 ? "OK\n" : "Necesita mentenanta!\n");
        }
        else if (dynamic_cast<const Tramvai*>(vehicul.get())) {
            const int starePantograf = proc(gen), stareBoghiu = proc(gen);
            std::cout << "Verificare pantograf ........... " << (starePantograf > 25 ? "OK\n" : "Necesita mentenanta!\n");
            std::cout << "Verificare boghiu .............. " << (stareBoghiu > 25 ? "OK\n" : "Necesita mentenanta!\n");
        }
        else if (dynamic_cast<const Troleibuz*>(vehicul.get())) {
            const int stareCaptatoare = proc(gen), starePneuri = proc(gen);
            std::cout << "Verificare captatoare .......... " << (stareCaptatoare > 25 ? "OK\n" : "Necesita mentenanta!\n");
            std::cout << "Verificare pneuri .............. " << (starePneuri > 25 ? "OK\n" : "Necesita mentenanta!\n");
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Depou& d) {
    out << "(ID " << d.id << ") Depoul " << d.nume << " -~- Inventar\n";
    for (const auto& vehicul : d.vehicule) {
        out << *vehicul;
    }
    return out;
}

void swap(Depou& a, Depou& b) {
    using std::swap;
    swap(a.capacitateMax, b.capacitateMax);
    swap(a.nume, b.nume);
    swap(a.vehicule, b.vehicule);
}

int Depou::contorId = 0;
