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
#include "DriverNotFoundException.h"
#include "FleetException.h"
#include "RouteNotFoundException.h"
#include "VehicleNotFoundException.h"

/**
 * @class FleetManager
 * @brief Manages the fleet system including drivers, vehicles, and routes.
 */
class FleetManager
{
private:
    std::vector<Driver> drivers;
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    std::vector<Route> routes;

public:
    FleetManager(std::vector<Driver> drivers,
                 std::vector<std::unique_ptr<Vehicle>> vehicles,
                 std::vector<Route> routes);

    FleetManager(const FleetManager& other);
    FleetManager& operator=(FleetManager other);

    friend void swap(FleetManager& first, FleetManager& second) noexcept;

    ~FleetManager() = default;

    void addDriver(const Driver& driver);
    void removeDriverById(int id);

    void addRoute(const Route& route);
    void removeRouteById(int id);

    void addVehicle(std::unique_ptr<Vehicle> vehicle);
    void removeVehicleByVin(int vin);

    void displayFleet() const;


    std::vector<Driver>& getDrivers();
    const std::vector<Driver>& getDrivers() const;


    std::vector<std::unique_ptr<Vehicle>>& getVehicles();
    const std::vector<std::unique_ptr<Vehicle>>& getVehicles() const;
};

#endif // FLEETMANAGER_H
