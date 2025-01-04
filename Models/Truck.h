#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

/**
 * @class Truck
 * @brief Represents a truck, derived from the Vehicle class.
 */
class Truck : public Vehicle
{
private:
    double loadCapacity;    // in tons
    double fuelEfficiency;  // in L/100km

public:
    Truck(int vin, const std::string& model, int kilometers,
          const std::string& brand, double loadCapacity, double fuelEfficiency);

    Truck(const Truck& other);

    Truck& operator=(Truck other);

    friend void swap(Truck& first, Truck& second) noexcept;

    ~Truck() override = default;

    void display() const override;
    void performMaintenance() override;
    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override;
    [[nodiscard]] double calculateMaintenanceCost() const override;

    [[nodiscard]] double getLoadCapacity() const;
    [[nodiscard]] double getFuelEfficiency() const;

    void increaseLoadCapacity(double extraTons);

};

#endif // TRUCK_H
