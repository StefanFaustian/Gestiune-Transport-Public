#include "Depou.h"
#include "Autobuz.h"
#include "Exceptii.h"
#include <algorithm> // pentru std::find_if()

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

bool Depou::eliminaVehicul(const std::string& nr) {
    const auto it = std::find_if(vehicule.begin(), vehicule.end(),
        [&nr](const std::shared_ptr<Vehicul>& v) {
            return v->getNrInmatriculare() == nr;
        });

    if (it != vehicule.end()) {
        vehicule.erase(it);
        return true;
    }

    return false; // Nu s-a găsit în acest depou
}

std::shared_ptr<Vehicul> Depou::cautaVehicul(const std::string& nrInmatriculare) {
    const auto it = std::find_if(vehicule.begin(), vehicule.end(),
        [&nrInmatriculare](const std::shared_ptr<Vehicul>& v) { return v->getNrInmatriculare() == nrInmatriculare;});

    if (it != vehicule.end()) {
        return *it;
    }
    return nullptr; // cazul in care nu a fost gasit vehiculul cautat
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
