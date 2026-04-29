#pragma once

#include "Vehicul.h"

class Tramvai : public Vehicul {
    void afisare(std::ostream& out) const override;
    int nrVagoane = 0;
    static constexpr int MAX_VAGOANE = 4;
public:
    Tramvai() = default;
    Tramvai(std::string numar, int cap, int vagoane, int km = 0);

    // Constructor de copiere
    Tramvai(const Tramvai& other);

    Tramvai* clone() const override;
    bool necesitaRevizie() const override;

    // Operatorul =
    Tramvai& operator=(Tramvai other);

    // Functie prieten swap
    friend void swap(Tramvai& a, Tramvai& b) noexcept;

    ~Tramvai() override;
};