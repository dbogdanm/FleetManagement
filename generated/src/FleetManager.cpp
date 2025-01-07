#include "FleetManager.h"
#include <iostream>
#include <iomanip>

/**
 * @brief Constructor for FleetManager.
 * @param drivers Vector of drivers.
 * @param vehicles Vector of unique pointers to vehicles.
 * @param routes Vector of routes.
 *
 * Initializes the fleet manager with drivers, vehicles, and routes.
 */
FleetManager::FleetManager(std::vector<Driver> drivers,
                           std::vector<std::unique_ptr<Vehicle>> vehicles,
                           std::vector<Route> routes)
    : drivers(std::move(drivers)),
      vehicles(std::move(vehicles)),
      routes(std::move(routes))
{
}

/**
 * @brief Copy constructor for FleetManager.
 * @param other Another FleetManager object to copy from.
 *
 * Creates a deep copy of vehicles and shallow copies of drivers and routes.
 */
FleetManager::FleetManager(const FleetManager& other)
{
    drivers = other.drivers;
    vehicles.clear();
    for (const auto& v : other.vehicles)
    {
        vehicles.emplace_back(v->clone());
    }
    routes = other.routes;
}

/**
 * @brief Copy assignment operator using copy-and-swap idiom.
 * @param other Another FleetManager object to assign from.
 * @return Reference to the current object.
 */
FleetManager& FleetManager::operator=(FleetManager other)
{
    swap(*this, other);
    return *this;
}

/**
 * @brief Swaps two FleetManager objects.
 * @param first First FleetManager object.
 * @param second Second FleetManager object.
 */
void swap(FleetManager& first, FleetManager& second) noexcept
{
    using std::swap;
    swap(first.drivers, second.drivers);
    swap(first.vehicles, second.vehicles);
    swap(first.routes, second.routes);
}

/**
 * @brief Adds a driver to the fleet.
 * @param driver The driver to add.
 */
void FleetManager::addDriver(const Driver& driver)
{
    drivers.push_back(driver);
}

/**
 * @brief Removes a driver by ID.
 * @param id The ID of the driver to remove.
 * @throws DriverNotFoundException if the driver ID is not found.
 */
void FleetManager::removeDriverById(int id)
{
    auto it = std::remove_if(drivers.begin(), drivers.end(),
                             [id](const Driver& d) {
                                 return d.getId() == id;
                             });
    if (it == drivers.end())
    {
        throw DriverNotFoundException(id);
    }
    drivers.erase(it, drivers.end());
}

/**
 * @brief Adds a route to the fleet.
 * @param route The route to add.
 */
void FleetManager::addRoute(const Route& route)
{
    routes.push_back(route);
}

/**
 * @brief Removes a route by ID.
 * @param id The ID of the route to remove.
 * @throws RouteNotFoundException if the route ID is not found.
 */
void FleetManager::removeRouteById(int id)
{
    auto it = std::remove_if(routes.begin(), routes.end(),
                             [id](const Route& r) {
                                 return r.getId() == id;
                             });
    if (it == routes.end())
    {
        throw RouteNotFoundException(id);
    }
    routes.erase(it, routes.end());
}

/**
 * @brief Adds a vehicle to the fleet.
 * @param vehicle Unique pointer to the vehicle to add.
 */
void FleetManager::addVehicle(std::unique_ptr<Vehicle> vehicle)
{
    vehicles.emplace_back(std::move(vehicle));
}

/**
 * @brief Removes a vehicle by VIN.
 * @param vin The VIN of the vehicle to remove.
 * @throws VehicleNotFoundException if the vehicle VIN is not found.
 */
void FleetManager::removeVehicleByVin(int vin)
{
    auto it = std::remove_if(vehicles.begin(), vehicles.end(),
                             [vin](const std::unique_ptr<Vehicle>& v) {
                                 return v->getVin() == vin;
                             });
    if (it == vehicles.end())
    {
        throw VehicleNotFoundException(vin);
    }
    vehicles.erase(it, vehicles.end());
}

/**
 * @brief Displays information about all drivers, vehicles, and routes.
 *
 * Iterates through the fleet and displays details of drivers, vehicles,
 * and routes, including specific details for different vehicle types.
 */
void FleetManager::displayFleet() const
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

        if (auto bus = dynamic_cast<Bus*>(vehicle.get()))
        {
            std::cout << "This is a Bus with seating capacity: "
                      << bus->getSeatingCapacity() << std::endl;
        }
        else if (auto truck = dynamic_cast<Truck*>(vehicle.get()))
        {
            std::cout << "This is a Truck with load capacity of: "
                      << truck->getLoadCapacity() << " tons" << std::endl;
        }
        else if (auto motorcycle = dynamic_cast<Motorcycle*>(vehicle.get()))
        {
            std::cout << "This is a Motorcycle with engine displacement: "
                      << motorcycle->getEngineDisplacement() << "cc" << std::endl;
        }
    }

    std::cout << "\nRoutes:" << std::endl;

    for (const auto& route : routes)
    {
        route.display();
    }

    std::cout << "===============================" << std::endl;
}

/**
 * @brief Optimizes resource allocation for all vehicles.
 *
 * Calls `optimizeResourceAllocation` on each vehicle and displays
 * the optimization strategy and efficiency score.
 */
void FleetManager::optimizeAllVehicles()
{
    std::cout << "=== Vehicle Resource Optimization Report ===\n";

    for (const std::unique_ptr<Vehicle>& vehicle : vehicles)
    {
        if (vehicle)
        {
            std::pair<std::string, double> optimizationResult = vehicle->optimizeResourceAllocation();
            std::cout << "VIN: " << vehicle->getVin() << "\n"
                      << "  Strategy: " << optimizationResult.first << "\n"
                      << "  Efficiency Score: " << std::fixed << std::setprecision(2)
                      << optimizationResult.second << "\n"
                      << "------------------------------------------\n";
        }
        else
        {
            std::cout << "[Error] Null vehicle encountered in fleet!\n";
        }
    }
    std::cout << "=================================\n";
}
