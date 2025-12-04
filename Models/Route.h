#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <iostream>

using namespace std;

class Route {
private:
    string startLocation;
    string endLocation;
    double distanceKm;

public:
    Route(string start, string end, double dist)
        : startLocation(start), endLocation(end), distanceKm(dist) {}

    string getStartLocation() const { return startLocation; }
    string getEndLocation() const { return endLocation; }
    double getDistance() const { return distanceKm; }

    void displayInfo() const {
        cout << "Route: " << startLocation << " to " << endLocation 
             << " (" << distanceKm << " km)" << endl;
    }
};

#endif
