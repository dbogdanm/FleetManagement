#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H

#include <memory>
#include <string>
#include "Bus.h"
#include "Truck.h"
#include "Motorcycle.h"

/**
 * @brief Factory class for creating different types of vehicles.
 *
 * Provides a static method to instantiate vehicle objects based on a type string.
 */
class VehicleFactory
{
public:
    /**
     * @brief Creates a vehicle instance based on the given type.
     *
     * @param type The type of vehicle to create ("Bus", "Truck", "Motorcycle").
     * @return A unique pointer to the created vehicle.
     *
     * @note Returns nullptr if the type is unknown.
     */
    static std::unique_ptr<Vehicle> createVehicle(const std::string& type);
};

#endif // VEHICLE_FACTORY_H
