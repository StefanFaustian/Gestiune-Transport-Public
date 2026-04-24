#pragma once

#include "Depou.h"
#include <string>
#include <unordered_set>
#include <vector>

class Manager {
    std::string numeManager;
    std::unordered_set<std::string> numereInmatriculate;
    void incarcaFlota(Depou& depou, const std::string& numeFisier);
    std::vector<Depou> depouri;
public:
    void afis();
    explicit Manager(const std::string& nume);
    void incarcaDepouri(const std::string& numeFisier);
};