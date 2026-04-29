#pragma once
#include <string>
#include "Exceptii.h"

static inline void trim(std::string& s) {
    s.erase(0,s.find_first_not_of(" \n\r\t"));
    s.erase(s.find_last_not_of(" \n\r\t")+1);
}

inline int safeStoi(const std::string& str, const std::string& atribut) {
    try {
        return std::stoi(str);
    } catch (const std::exception&) {
        throw EroareFisier("Eroare conversie numar pentru *" + atribut + "*: valoarea \"" + str + "\" este invalida.");
    }
}