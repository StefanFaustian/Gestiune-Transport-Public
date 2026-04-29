#pragma once

#include <stdexcept>


// Baza pentru ierarhia de exceptii
class EroareGenerala : public std::runtime_error {
public:
    explicit EroareGenerala(const std::string& mesaj) : std::runtime_error(mesaj) {}
};

class EroareValidareVehicul : public EroareGenerala {
public:
    explicit EroareValidareVehicul(const std::string& mesaj) : EroareGenerala("EROARE VALIDARE VEHICUL: " + mesaj) {}
};

class EroareOperatiune : public EroareGenerala {
public:
    explicit EroareOperatiune(const std::string& mesaj) : EroareGenerala("EROARE OPERATIUNE: " + mesaj) {}
};

class EroareFisier : public EroareGenerala {
public:
    explicit EroareFisier(const std::string& mesaj) : EroareGenerala("EROARE FISIER: " + mesaj) {}
};

class EroareCapacitateDepou : public EroareGenerala {
public:
    explicit EroareCapacitateDepou(const std::string& nume) : EroareGenerala("\nCapacitate depasita: Depoul " + nume + " este plin!") {}
};

class EroareValidareDepou : public EroareGenerala {
public:
    explicit EroareValidareDepou(const std::string& mesaj) : EroareGenerala("EROARE VALIDARE " + mesaj) {}
};

