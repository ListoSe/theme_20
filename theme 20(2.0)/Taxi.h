#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Taxi {
public:
    int number;
    string brand;
    string driver;
    bool isbusy;

    Taxi(int num, string br, string dr, bool busy) {
        number = num;
        brand = br;
        driver = dr;
        isbusy = busy;
    }

    void print_info() {
        cout << "Taxi " << number << ", " << brand << ", driver: " << driver;
        if (isbusy) {
            cout << " is currently busy" << endl;
        }
        else {
            cout << " is currently available" << endl;
        }
    }

    void set_busy()
    {
        isbusy = true;
    }

    void set_available()
    {
        isbusy = false;
    }
};

class TaxiSystem {
public:
    vector<Taxi> taxis;

    void add_taxi(int num, string br, string dr) {
        Taxi new_taxi(num, br, dr, false);
        taxis.push_back(new_taxi);
    }

    void print_all_taxis() {
        for (int i = 0; i < taxis.size(); i++) {
            taxis[i].print_info();
        }
    }

    void add_taxi_before(int num, string br, string dr, int pos) {
        Taxi new_taxi(num, br, dr, false);
        taxis.insert(taxis.begin() + pos, new_taxi);
    }

    void remove_taxi(int num) {
        for (int i = 0; i < taxis.size(); i++) {
            if (taxis[i].number == num) {
                taxis.erase(taxis.begin() + i);
                break;
            }
        }
    }

    void set_taxi_busy(int num) {
        for (int i = 0; i < taxis.size(); i++) {
            if (taxis[i].number == num) {
                taxis[i].set_busy();
                break;
            }
        }
    }

    void set_taxi_available(int num) {
        for (int i = 0; i < taxis.size(); i++) {
            if (taxis[i].number == num) {
                taxis[i].set_available();
                break;
            }
        }
    }

    void print_busy_taxis() {
        cout << "Busy taxis:" << endl;
        for (int i = 0; i < taxis.size(); i++) {
            if (taxis[i].isbusy) {
                taxis[i].print_info();
            }
        }
    }

    void print_available_taxis() {
        cout << "Available taxis:" << endl;
        for (int i = 0; i < taxis.size(); i++) {
            if (!taxis[i].isbusy) {
                taxis[i].print_info();
            }
        }
    }
};

