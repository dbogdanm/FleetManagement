#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Driver.h"
#include "Route.h"
#include "Vehicle.h"
#include "Helper.h"

using namespace std;

class FleetManager
{
private:
    vector<Driver> drivers;
    vector<Vehicle> vehicles;
    vector<Route> routes;

public:
    FleetManager(const vector<Driver> &drivers, const vector<Vehicle> &vehicles, const vector<Route> &routes)
        : drivers(drivers),
          vehicles(vehicles),
          routes(routes)
    {
    }

    friend ostream& operator<<(ostream& os, const FleetManager& fleetManager)
    {
        os << "Drivers:" << endl;
        for (const Driver& driver : fleetManager.drivers)
            os << driver << endl;

        os << "Vehicles:" << endl;
        for (const Vehicle& vehicle : fleetManager.vehicles)
            os << vehicle << endl;

        os << "Routes:" << endl;
        for (const Route& route : fleetManager.routes)
            os << route << endl;

        return os;
    }



    void addDriver(const Driver &driver)
    {
        drivers.push_back(driver);
    }

    void addVehicle(const Vehicle &vehicle)
    {
        vehicles.push_back(vehicle);
    }

    void addRoute(const Route &route)
    {
        routes.push_back(route);
    }

    void removeDriver(const Driver &driver)
    {
        drivers.erase(remove(drivers.begin(), drivers.end(), driver), drivers.end());
    }

    void removeVehicle(const Vehicle &vehicle)
    {
        vehicles.erase(remove(vehicles.begin(), vehicles.end(), vehicle), vehicles.end());
    }

    void removeRoute(const Route &route)
    {
        routes.erase(remove(routes.begin(), routes.end(), route), routes.end());
    }

    vector<Driver> GetDrivers() const
    {
        return drivers;
    }

    vector<Vehicle> GetVehicles() const
    {
        return vehicles;
    }

    vector<Route> GetRoutes() const
    {
        return routes;
    }

    ~FleetManager() = default;
    //vector is already self managing its memory

};

#endif //FLEETMANAGER_H
