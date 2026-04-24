// Constructori virtuali

#include "Manager.h"
#include <iostream>

#include "Exceptii.h"


int main() {

    Manager SA("STB SA");
    try {
        SA.incarcaDepouri("Depouri.txt");

    } catch (const EroareGenerala& err) {
        std::cerr << err.what() << '\n';
    }

    SA.afis();
    return 0;
}
