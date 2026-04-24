#include "Manager.h"
#include "Exceptii.h"
#include "Autobuz.h"
#include "Tramvai.h"
#include "Troleibuz.h"
#include "Utilitare.h"
#include <fstream>
#include <sstream>
#include <algorithm> // pentru transform

Manager::Manager(const std::string& nume) : numeManager(nume) {}

void Manager::afis() {
    for (auto& dep : depouri) {
        std::cout << dep << std::endl;
    }
}

void Manager::incarcaDepouri(const std::string& numeFisier) {
    std::ifstream fin(numeFisier);
    if (!fin.is_open()) {
        throw EroareFisier("Fisierul " + numeFisier + " nu poate fi gasit.");
    }

    std::string linie;
    while (std::getline(fin,linie)) {
        // sunt excluse liniile goale si cele comentate cu '#'
        trim(linie);
        if (linie.empty() || linie[0] == '#') continue;

        std::stringstream linieParse(linie); // parsare pentru split
        std::string numeDepou, capacitateStr, numeFisierSursa;
        if (!(std::getline(linieParse, numeDepou, ',') &&
        std::getline(linieParse, capacitateStr, ',') &&
        std::getline(linieParse, numeFisierSursa))) { //  || numeDepou.empty() || numeFisierSursa.empty()

            throw EroareFisier("Citirea a esuat pentru ca linia " + linie + " nu respecta formatul de input");
        }
        trim(numeDepou), trim(capacitateStr), trim(numeFisierSursa);
        try {
            int capacitate = std::stoi(capacitateStr);
            depouri.emplace_back(Depou(numeDepou,capacitate));
            incarcaFlota(depouri.back(),numeFisierSursa);
        } catch (const std::exception& err) {
            std::cerr << "Eroare la conversia capacitatii depoului de la linia " << linie << ". (Nu se poate aplica " << err.what() << " pe \"" << capacitateStr << "\")\n";
        }
    }
}

void Manager::incarcaFlota(Depou& depou, const std::string& numeFisier) {
    std::cout << numeFisier << '\n';
    std::ifstream fin(numeFisier);
    if (!fin.is_open()) {
        throw EroareOperatiune("Fisierul " + numeFisier + " nu poate fi gasit.");
    }

    std::string linie;
    while (std::getline(fin,linie)) {
        // sunt excluse liniile goale si cele comentate cu '#'
        trim(linie);
        if (linie.empty() || linie[0] == '#') continue;

        std::string tipVehicul, nrInmatriculare, capacitateStr;
        try {
            std::stringstream linieParse(linie);
            if (!(std::getline(linieParse, tipVehicul, ',') &&
                  std::getline(linieParse, nrInmatriculare, ',') &&
                  std::getline(linieParse, capacitateStr, ','))) {
                throw EroareFisier("Citirea a esuat pentru ca linia " + linie + " nu respecta formatul de input.");
            }
            if (numereInmatriculate.count(nrInmatriculare))
                throw EroareOperatiune("Numarul de inmatriculare " + nrInmatriculare + " este deja folosit.");

            trim(tipVehicul), trim(nrInmatriculare), trim(capacitateStr);
            int capacitate = std::stoi(capacitateStr);

            // Tratare cazuri case-sensitive
            std::transform(tipVehicul.begin(),tipVehicul.end(),tipVehicul.begin(),tolower);
            std::transform(nrInmatriculare.begin(),nrInmatriculare.end(),nrInmatriculare.begin(),toupper);

            std::shared_ptr<Vehicul> vehicul = nullptr;
            if (tipVehicul == "autobuz") {
                std::string motor;
                if (!std::getline(linieParse, motor, ','))
                    throw EroareFisier("Citirea a esuat pentru ca linia " + linie + " nu respecta formatul de input pentru autobuze.");

                trim(motor);
                vehicul = std::make_shared<Autobuz>(nrInmatriculare,capacitate,motor);

            } else if (tipVehicul == "tramvai") {
                std::string nrVagoaneStr;
                if (!std::getline(linieParse, nrVagoaneStr, ','))
                    throw EroareFisier("Citirea a esuat pentru ca linia " + linie + " nu respecta formatul de input pentru tramvaie.");

                trim(nrVagoaneStr);
                int nrVagoane = std::stoi(nrVagoaneStr);
                vehicul = std::make_shared<Tramvai>(nrInmatriculare,capacitate,nrVagoane);

            } else if (tipVehicul == "troleibuz") {
                std::string baterieStr;
                if (!std::getline(linieParse, baterieStr, ','))
                    throw EroareFisier("Citirea a esuat pentru ca linia " + linie + " nu respecta formatul de input pentru troleibuze.");

                trim(baterieStr);
                std::transform(baterieStr.begin(), baterieStr.end(), baterieStr.begin(), tolower);
                bool baterie = (baterieStr == "true" || baterieStr == "1");
                vehicul = std::make_shared<Troleibuz>(nrInmatriculare,capacitate,baterie);

            } else {
                throw EroareFisier("Tip de vehicul neidentificat: " + tipVehicul + '\n');
            }

            depou.adaugaVehicul(vehicul);
            numereInmatriculate.insert(nrInmatriculare);

        } catch (const EroareGenerala& err) {
            std::cerr << err.what() << '\n';
        } catch (const std::exception& err) {
            std::cerr << "Eroare la conversia capacitatii vehiculului de la linia " << linie << ". (Nu se poate aplica " << err.what() << " pe \"" << capacitateStr << "\")\n";
        }
    }
}
