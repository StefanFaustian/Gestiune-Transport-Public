 #pragma once

#include <string>
#include <iostream>

class Vehicul {
    static int contorId;
    virtual void afisare(std::ostream&) const = 0;
protected:
    const int id;
    int capacitateMax = 0;
    int nrKM = 0;
    int nrKmUltimaRevizie = 0;
    std::string nrInmatriculare;



public:
    Vehicul();

    // Constructor
    Vehicul(const std::string& numar, int cap, int km = 0);

    // Constructor de mutare
    Vehicul(Vehicul&& other) noexcept;

    // Constructor de copiere
    Vehicul(const Vehicul& other);

    // Operator de atribuire
    Vehicul& operator=(const Vehicul& other);

    // Destructor
    virtual ~Vehicul();

    virtual Vehicul* clone() const = 0;

    virtual bool necesitaRevizie() const = 0; // functie virtuala specifica temei

    // Funcție statica
    // static int getTotalVehicule();

    // Afisare
    friend std::ostream& operator<<(std::ostream& out, const Vehicul& v);

    void actualizeazaKM (const int km) { nrKM += km; }

    void efectueazaRevizie() { nrKmUltimaRevizie = nrKM; }

    friend void swap(Vehicul& a, Vehicul& b) noexcept;

    // Getters
    std::string getNrInmatriculare() const { return nrInmatriculare; }

};