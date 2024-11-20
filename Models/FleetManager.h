#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Driver.h"
#include "Route.h"
#include "Vehicle.h"
#include "Helper.h"


class FleetManager
{
private:
    std::vector<Driver> drivers;
    std::vector<Vehicle> vehicles;
    std::vector<Route> routes;

public:
    FleetManager(const std::vector<Driver> &drivers, const std::vector<Vehicle> &vehicles, const std::vector<Route> &routes)
        : drivers(drivers),
          vehicles(vehicles),
          routes(routes)
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const FleetManager& fleetManager)
    {
        os << "Drivers:" << std::endl;
        for (const Driver& driver : fleetManager.drivers)
            os << driver << std::endl;

        os << "Vehicles:" << std::endl;
        for (const Vehicle& vehicle : fleetManager.vehicles)
            os << vehicle << std::endl;

        os << "Routes:" << std::endl;
        for (const Route& route : fleetManager.routes)
            os << route << std::endl;

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


    std::vector<Driver> GetDrivers() const
    {
        return drivers;
    }

    std::vector<Vehicle> GetVehicles() const
    {
        return vehicles;
    }

    std::vector<Route> GetRoutes() const
    {
        return routes;
    }

    Driver FindDriverById(int id) const
    {
        for (const Driver &driver : drivers)
        {
            if (driver.GetId() == id)
            {
                std::cout << "Driver found!" << std::endl;
                return driver; std::cout<< '\n';
            }
        }
        std::cout<< "Driver not found" << std::endl;
    }


    ~FleetManager() = default;
    //vector is already self managing its memory

};

#endif //FLEETMANAGER_H
