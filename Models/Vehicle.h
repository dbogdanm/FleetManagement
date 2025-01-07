#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <memory>

/**
 * @class Vehicle
 * @brief Abstract base class for vehicles.
 */
class Vehicle
{
protected:
    int vin; ///< Vehicle Identification Number.
    std::string model; ///< Model name.
    int kilometers; ///< Kilometers driven.
    std::string brand; ///< Brand name.

public:
    Vehicle(int vin, std::string model, int kilometers, std::string brand); ///< Constructor.
    Vehicle(const Vehicle& other); ///< Copy constructor.
    virtual ~Vehicle() = default; ///< Virtual destructor.

    virtual void display() const = 0; ///< Display details.
    virtual void performMaintenance() = 0; ///< Perform maintenance.
    virtual std::unique_ptr<Vehicle> clone() const = 0; ///< Clone vehicle.
    virtual double calculateMaintenanceCost() const = 0; ///< Calculate maintenance cost.
    virtual std::pair<std::string, double> optimizeResourceAllocation() const = 0; ///< Optimize resources.

    void showInfo() const; ///< Display basic info.
    int getVin() const; ///< Get VIN.

protected:
    void swapBase(Vehicle& other) noexcept; ///< Swap base attributes.

public:
    Vehicle& operator=(const Vehicle& other) = delete; ///< Delete assignment operator.
};

#endif // VEHICLE_H
