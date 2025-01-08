#include "../generated/headers/VehicleFactory.h"
#include <stdexcept>

/**
 * @brief Creates a specific type of vehicle.
 *
 * @param type The type of vehicle to create ("Bus", "Truck", "Motorcycle").
 * @return A unique pointer to the created vehicle.
 *
 * @throws std::invalid_argument If the type is not recognized.
 *
 * Creates an instance of a `Bus`, `Truck`, or `Motorcycle` based on the input type
 * and returns it as a `std::unique_ptr<Vehicle>`.
 */
std::unique_ptr<Vehicle> VehicleFactory::createVehicle(const std::string& type)
{
    if (type == "Bus")
    {
        return std::make_unique<Bus>(
            201, "CityBus", 10000, "Mercedes",
            50, true,      // seatingCapacity, hasWiFi
            85, 32, 90,    // brakeHealth, tirePressure, engineHealth
            true, 88       // safetySystemsFunctional, electronicSystemsHealth
        );
    }
    else if (type == "Truck")
    {
        return std::make_unique<Truck>(
            202, "FreightTruck", 5000, "Volvo",
            15.0, 8.5,    // loadCapacity, fuelEfficiency
            80, 35, 95,   // brakeHealth, tirePressure, engineHealth
            true, 92      // safetySystemsFunctional, electronicSystemsHealth
        );
    }
    else if (type == "Motorcycle")
    {
        return std::make_unique<Motorcycle>(
            203, "Speedster", 2000, "Yamaha",
            600.0, false,  // engineDisplacement, hasSidecar
            75, 29, 85,    // brakeHealth, tirePressure, engineHealth
            true, 80       // safetySystemsFunctional, electronicSystemsHealth
        );
    }

    throw std::invalid_argument("Unknown vehicle type");
}

