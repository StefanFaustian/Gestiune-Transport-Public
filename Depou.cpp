#include "Depou.h"
#include "Autobuz.h"
#include "Tramvai.h"
#include "Troleibuz.h"
#include <random>

Depou::Depou(const std::string& nume_) : nume(nume_) {}

Depou::~Depou() = default;

void Depou::adaugaVehicul(Vehicul* v) {
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
    out << "Depoul " << d.nume << " -~- Inventar\n";
    for (const auto& vehicul : d.vehicule) {
        std::cout << *vehicul;
    }
    return out;
}
