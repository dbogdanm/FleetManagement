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

    FleetManager& operator=(const FleetManager &other)
    {
        if (this != &other)
        {
            drivers = other.drivers;
            vehicles = other.vehicles;
            routes = other.routes;
        }
        return *this;
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

    void removeDriverById(int id)
    {
        drivers.erase(remove_if(drivers.begin(), drivers.end(), [id](const Driver &driver) { return driver.GetId() == id; }), drivers.end());
    }

    void removeVehicleByVin(int index)
    {
        vehicles.erase(remove_if(vehicles.begin(), vehicles.end(), [index](const Vehicle &vehicle) { return vehicle.GetVin() == index; }), vehicles.end());
    }

    void removeRouteById(int routeId)
    {
        routes.erase(remove_if(routes.begin(), routes.end(),
                   [routeId](const Route &route) { return route.GetId() == routeId; }),
                   routes.end());
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

    Driver FindDriverById(int id) const
    {
        for (const Driver &driver : drivers)
        {
            if (driver.GetId() == id)
            {
                cout << "Driver found!" << endl;
                return driver; cout<< '\n';
            }
        }
        cout<< "Driver not found" << endl;
    }


    ~FleetManager() = default;
    //vector is already self managing its memory

};

#endif //FLEETMANAGER_H
