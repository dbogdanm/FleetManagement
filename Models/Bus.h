#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"
#include <memory>

/**
 * @class Bus
 * @brief Represents a bus vehicle.
 */
class Bus : public Vehicle
{
private:
    int seatingCapacity; ///< Number of seats.
    bool hasWiFi; ///< WiFi availability.

public:
    Bus(int vin, const std::string& model, int kilometers,
        const std::string& brand, int seatingCapacity, bool hasWiFi); ///< Constructor.
    Bus(const Bus& other); ///< Copy constructor.
    Bus& operator=(Bus other); ///< Copy assignment.

    friend void swap(Bus& first, Bus& second) noexcept; ///< Swap two buses.

    ~Bus() override = default; ///< Destructor.

    void display() const override; ///< Show bus details.
    void performMaintenance() override; ///< Perform maintenance.
    std::unique_ptr<Vehicle> clone() const override; ///< Clone bus.
    double calculateMaintenanceCost() const override; ///< Calculate maintenance cost.
    std::pair<std::string, double> optimizeResourceAllocation() const override; ///< Optimize resources.

    int getSeatingCapacity() const; ///< Get seating capacity.
    bool getHasWiFi() const; ///< Check WiFi availability.

    void upgradeWiFi(); ///< Upgrade WiFi.
    void increaseSeatingCapacity(int extraSeats); ///< Add seats.
};

#endif // BUS_H
