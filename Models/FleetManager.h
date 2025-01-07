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
#include "../Exceptions/DriverNotFoundException.h"
#include "../Exceptions/FleetException.h"
#include "../Exceptions/RouteNotFoundException.h"
#include "../Exceptions/VehicleNotFoundException.h"

/**
 * @class FleetManager
 * @brief Manages drivers, vehicles, and routes in a fleet system.
 */
class FleetManager
{
private:
    std::vector<Driver> drivers; ///< List of drivers.
    std::vector<std::unique_ptr<Vehicle>> vehicles; ///< List of vehicles.
    std::vector<Route> routes; ///< List of routes.

public:
    FleetManager(std::vector<Driver> drivers,
                 std::vector<std::unique_ptr<Vehicle>> vehicles,
                 std::vector<Route> routes); ///< Constructor.

    FleetManager(const FleetManager& other); ///< Copy constructor.
    FleetManager& operator=(FleetManager other); ///< Copy assignment operator.

    friend void swap(FleetManager& first, FleetManager& second) noexcept; ///< Swap two FleetManager objects.

    ~FleetManager() = default; ///< Destructor.

    void addDriver(const Driver& driver); ///< Add a driver.
    void removeDriverById(int id); ///< Remove a driver by ID.

    void addRoute(const Route& route); ///< Add a route.
    void removeRouteById(int id); ///< Remove a route by ID.

    void addVehicle(std::unique_ptr<Vehicle> vehicle); ///< Add a vehicle.
    void removeVehicleByVin(int vin); ///< Remove a vehicle by VIN.

    void displayFleet() const; ///< Display fleet details.
    void optimizeAllVehicles(); ///< Optimize resources for all vehicles.

    std::vector<Driver>& getDrivers(); ///< Get drivers (modifiable).
    const std::vector<Driver>& getDrivers() const; ///< Get drivers (read-only).

    std::vector<std::unique_ptr<Vehicle>>& getVehicles(); ///< Get vehicles (modifiable).
    const std::vector<std::unique_ptr<Vehicle>>& getVehicles() const; ///< Get vehicles (read-only).
};

#endif // FLEETMANAGER_H
