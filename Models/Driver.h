#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>

using namespace std;

class Driver {
private:
    string name;
    string licenseId;
    int experienceYears;

public:
    Driver(string n, string l, int e) 
        : name(n), licenseId(l), experienceYears(e) {}

    string getName() const { return name; }
    string getLicenseId() const { return licenseId; }
    int getExperience() const { return experienceYears; }

    void displayInfo() const {
        cout << "Driver: " << name << " [ID: " << licenseId 
             << "], Exp: " << experienceYears << " years" << endl;
    }
};

#endif
