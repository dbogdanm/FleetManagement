#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "Driver.h"
#include "Route.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "C:\Users\gicap\OneDrive\Desktop\OOP\Project\Exceptions\DriverNotFoundException.h"
#include "C:\Users\gicap\OneDrive\Desktop\OOP\Project\Exceptions\FleetException.h"
#include "C:\Users\gicap\OneDrive\Desktop\OOP\Project\Exceptions\RouteNotFoundException.h"
#include "C:\Users\gicap\OneDrive\Desktop\OOP\Project\Exceptions\VehicleNotFoundException.h"

class FleetManager
{
private:
    std::vector<Driver> drivers;
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    std::vector<Route> routes;

public:

    FleetManager(std::vector<Driver> drivers,
                std::vector<std::unique_ptr<Vehicle>> vehicles,
                std::vector<Route> routes)
        : drivers(std::move(drivers)),
          vehicles(std::move(vehicles)),
          routes(std::move(routes)) {}


    FleetManager(const FleetManager& other)
    {
        drivers = other.drivers;

        vehicles.clear();
        for (const auto& v : other.vehicles)
        {
            vehicles.emplace_back(v->clone());
        }
        routes = other.routes;
    }

    // DE SCRIS copy and swap aici
    FleetManager& operator=(FleetManager other)
    {
        swap(*this, other);
        return *this;
    }

    // DE IMPLEMENTAT SWAP FUNCTION AICI!!!
    //nu stiu ce face noexcept, l-am adaugat din clion ca fix pt un warning
    friend void swap(FleetManager& first, FleetManager& second) noexcept
    {
        using std::swap;
        swap(first.drivers, second.drivers);
        swap(first.vehicles, second.vehicles);
        swap(first.routes, second.routes);
    }


    ~FleetManager() = default;


    void addDriver(const Driver& driver)
    {
        drivers.push_back(driver);
    }


    void removeDriverById(int id)
    {
        auto it = std::remove_if(drivers.begin(), drivers.end(),
                                 [id](const Driver& d)
                                 {
                                     return d.getId() == id;
                                 });
        if (it == drivers.end())
        {
            throw DriverNotFoundException(id);
        }
        drivers.erase(it, drivers.end());
    }


    void addRoute(const Route& route)
    {
        routes.push_back(route);
    }


    void removeRouteById(int id)
    {
        auto it = std::remove_if(routes.begin(), routes.end(),
                                 [id](const Route& r)
                                 {
                                     return r.getId() == id;
                                 });
        if (it == routes.end())
        {
            throw RouteNotFoundException(id);
        }
        routes.erase(it, routes.end());
    }


    void addVehicle(std::unique_ptr<Vehicle> vehicle)
    {
        vehicles.emplace_back(std::move(vehicle));
    }


    void removeVehicleByVin(int vin)
    {
        auto it = std::remove_if(vehicles.begin(), vehicles.end(),
                                 [vin](const std::unique_ptr<Vehicle>& v)
                                 {
                                     return v->getVin() == vin;
                                 });
        if (it == vehicles.end())
        {
            throw VehicleNotFoundException(vin);
        }
        vehicles.erase(it, vehicles.end());
    }


    void displayFleet() const
    {
        std::cout << "=== Fleet Information ===" << std::endl;
        std::cout << "\nDrivers:" << std::endl;


        for (const auto& driver : drivers)
        {
            driver.display();
        }
        std::cout << "\nVehicles:" << std::endl;

        for (const auto& vehicle : vehicles)
        {
            vehicle->display();
            // dynamic cast pt downcasting

            if (auto bus = dynamic_cast<Bus*>(vehicle.get()))
            {
                std::cout << "This is a Bus with seating capacity: " << bus->getSeatingCapacity() << std::endl;
            }

            else if (auto truck = dynamic_cast<Truck*>(vehicle.get()))
            {
                std::cout << "This is a Truck with load capacity of: " << truck->getLoadCapacity() << " tons" << std::endl;
            }

            else if (auto motorcycle = dynamic_cast<Motorcycle*>(vehicle.get()))
            {
                std::cout << "This is a Motorcycle with engine displacement: " << motorcycle->getEngineDisplacement() << "cc" << std::endl;
            }
        }

        std::cout << "\nRoutes:" << std::endl;

        for (const auto& route : routes)
        {
            route.display();
        }

        std::cout << "===============================" << std::endl;
    }
};

#endif // FLEETMANAGER_H
