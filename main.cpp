// Constructori virtuali

#include "Autobuz.h"
#include "Tramvai.h"
#include <iostream>

#include "Troleibuz.h"

int main() {
    Autobuz a1("B-101-S3", 90, "diesel");
    Autobuz a2("B-881-S2", 60, "electric");
    std::cout<<a1;
    std::cout<<a2;
    Tramvai t1("B-10001",120,3);
    std::cout<<t1;
    Troleibuz tb1("B-2028",75,false);
    std::cout<<tb1;
    return 0;
}
