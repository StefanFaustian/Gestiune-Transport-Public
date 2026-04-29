#include "Linie.h"
#include "Exceptii.h"
#include <algorithm> // pentru std::find_if()

std::unordered_set<std::string> Linie::vehiculeActivePeLinii;

Linie::Linie(const std::string& indicativ_, TipVehiculLinie tip) : indicativ(indicativ_), tipVehicul(tip) {}

void Linie::adaugaStatie(const std::string& numeStatie, int distanta) {
    const auto it = std::find_if(statii.begin(), statii.end(),
        [&numeStatie](const Statie& s) { return s.nume == numeStatie; }); // functie lambda
    if (it != statii.end()) {
        throw EroareOperatiune("Statia '" + numeStatie + "' exista deja pe linia " + indicativ + "!");
    }

    if (statii.empty())    // prima statie nu are o statie anterioara
        distanta = 0;

    statii.push_back({numeStatie,distanta});
}

void Linie::eliminaStatie(const std::string& numeStatie) {
    const auto it = std::find_if(statii.begin(), statii.end(),
        [&numeStatie](const Statie& s) { return s.nume == numeStatie; }); // functie lambda
    if (it == statii.end())
        throw EroareOperatiune("Statia '" + numeStatie + "' nu exista pe linia " + indicativ + "!");

    if (it + 1 != statii.end()) {  // daca statia de eliminat nu este ultima, adica are o statie succesoare
        if (it == statii.begin()) (it + 1)->distPrecedent = 0;  // daca statia de eliminat este prima, urmatoarea statie devine prima statie
        else (it + 1)->distPrecedent += it->distPrecedent;
    }

    statii.erase(it);
}

int Linie::calculeazaDistantaTurRetur() const {
    int sumaDistanta = 0;
    for (const auto& s : statii)
        sumaDistanta += s.distPrecedent;
    return 2 * sumaDistanta;
}

void Linie::trimiteVehicul(const std::string& nrInmatriculare) {
    if (vehiculeActivePeLinii.count(nrInmatriculare)) {
        throw EroareOperatiune("Vehiculul " + nrInmatriculare + " este deja pe traseu (pe aceasta linie sau pe alta)!");
    }

    vehiculeActivePeLinii.insert(nrInmatriculare);  // inserare intre vehiculele asignate unei linii
    vehiculePeTraseu.insert(nrInmatriculare);  // inserare intre vehiculele asignate liniei curente

    std::cout << "Vehiculul " << nrInmatriculare << " a intrat pe linia " << indicativ << ".\n";
}

void Linie::retrageVehicul(const std::string& nrInmatriculare) {
    if (vehiculePeTraseu.find(nrInmatriculare) == vehiculePeTraseu.end()) {
        throw EroareOperatiune("Vehiculul " + nrInmatriculare + " nu se afla pe linia " + indicativ + "!");
    }

    vehiculePeTraseu.erase(nrInmatriculare);    // stergere dintre vehiculele asignate liniei curente
    vehiculeActivePeLinii.erase(nrInmatriculare);   // stergere dintre vehiculele asignate unei linii

    std::cout << "Vehiculul " << nrInmatriculare << " a fost retras de pe linia " << indicativ << ".\n";
}

void Linie::retrageToataFlota() {
    // Stergere locala, apoi stergere globala
    for (const auto& nr : vehiculePeTraseu) {
        vehiculeActivePeLinii.erase(nr);
    }
    vehiculePeTraseu.clear();
}

std::ostream& operator<<(std::ostream& out, const Linie& linie) {
    out << "Linia " << linie.indicativ << "\n";
    out << "Tip vehicule | " << linie.tipVehicul << "e: ";
    for (const auto& vehicul : linie.vehiculePeTraseu)
        out << vehicul << " ";
    out << "\nStatiile: ";
    for (const auto& statie : linie.statii)
        out << statie.nume << "-->";
    out << "<--\n";
    return out;
}

std::ostream& operator<<(std::ostream& out, const TipVehiculLinie tip) {
    switch (tip) {
    case TipVehiculLinie::AUTOBUZ: out << "Autobuz"; break;
    case TipVehiculLinie::TRAMVAI: out << "Tramvai"; break;
    case TipVehiculLinie::TROLEIBUZ: out << "Troleibuz"; break;
    }
    return out;
}