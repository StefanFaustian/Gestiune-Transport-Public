// Constructori virtuali

#include "Autobuz.h"
#include "Tramvai.h"
#include "Troleibuz.h"
#include <iostream>



int main() {
    // Autobuz a1("B-101-S3", 90, "diesel");
    // Autobuz a2("B-881-S2", 60, "electric");
    // // Autobuz a2(a1);
    // std::cout<<a1;
    // std::cout<<a2;
    // Tramvai t1("B-10001",120,3);
    // Tramvai t2("B-6002",100,2);
    // std::cout<<t1;
    // std::cout<<t2;
    // t1 = t2;
    // std::cout<<t1;
    // std::cout<<t2;
    Troleibuz tb1("B-2028",75,false);
    Troleibuz tb2("B-3111",80,true);
    std::cout<<tb1;
    std::cout<<tb2;
    tb1 = tb2;
    std::cout<<tb1;
    // a1 = a2;
    // std::cout<<a1;
    // swap(t1,t2);
    return 0;
}
