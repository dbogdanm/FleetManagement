#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

/**
 * @class Truck
 * @brief Represents a truck vehicle.
 */
class Truck : public Vehicle
{
private:
    double loadCapacity; ///< Load capacity in tons.
    double fuelEfficiency; ///< Fuel efficiency in liters per 100 km.

public:
    Truck(int vin, const std::string& model, int kilometers,
          const std::string& brand, double loadCapacity, double fuelEfficiency); ///< Constructor.
    Truck(const Truck& other); ///< Copy constructor.
    Truck& operator=(Truck other); ///< Copy assignment operator.

    friend void swap(Truck& first, Truck& second) noexcept; ///< Swap two trucks.

    ~Truck() override = default; ///< Destructor.

    void display() const override; ///< Show truck details.
    void performMaintenance() override; ///< Perform maintenance.
    std::unique_ptr<Vehicle> clone() const override; ///< Clone truck.
    double calculateMaintenanceCost() const override; ///< Calculate maintenance cost.
    std::pair<std::string, double> optimizeResourceAllocation() const override; ///< Optimize resources.

    double getLoadCapacity() const; ///< Get load capacity.
    double getFuelEfficiency() const; ///< Get fuel efficiency.

    void increaseLoadCapacity(double extraTons); ///< Increase load capacity.
};

#endif // TRUCK_H
