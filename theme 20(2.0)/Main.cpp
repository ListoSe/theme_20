#include <iostream>
#include <list>
#include <string>
#include "Taxi.h"
using namespace std;

int main() {
    TaxiSystem system;


    system.add_taxi(1, "Volkswagen", "Polo");
    system.add_taxi(2, "Renau", "Duster");
    system.add_taxi(3, "Mazda", "CX-5");


    system.print_all_taxis();
    system.add_taxi_before(4, "Toyota", "Fornuter", 2);
    system.remove_taxi(2);
    system.set_taxi_busy(3);
}