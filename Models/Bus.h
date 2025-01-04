#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"
#include <memory>

/**
 * @class Bus
 * @brief Represents a bus, derived from the Vehicle class.
 */
class Bus : public Vehicle
{
private:
    int seatingCapacity;
    bool hasWiFi;

public:
    Bus(int vin, const std::string& model, int kilometers,
        const std::string& brand, int seatingCapacity, bool hasWiFi);

    Bus(const Bus& other);

    Bus& operator=(Bus other);

    friend void swap(Bus& first, Bus& second) noexcept;

    ~Bus() override = default;

    void display() const override;
    void performMaintenance() override;
    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override;
    [[nodiscard]] double calculateMaintenanceCost() const override;

    [[nodiscard]] int getSeatingCapacity() const;
    [[nodiscard]] bool getHasWiFi() const;

    void upgradeWiFi();

    void increaseSeatingCapacity(int extraSeats);

};

#endif // BUS_H
