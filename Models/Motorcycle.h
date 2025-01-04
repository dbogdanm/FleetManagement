#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

/**
 * @class Motorcycle
 * @brief Represents a motorcycle, derived from the Vehicle class.
 */
class Motorcycle : public Vehicle
{
private:
    double engineDisplacement; // cc
    bool hasSidecar;

public:
    Motorcycle(int vin, const std::string& model, int kilometers,
               const std::string& brand, double engineDisplacement, bool hasSidecar);

    Motorcycle(const Motorcycle& other);

    Motorcycle& operator=(Motorcycle other);

    friend void swap(Motorcycle& first, Motorcycle& second) noexcept;

    ~Motorcycle() override = default;

    void display() const override;
    void performMaintenance() override;
    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override;
    [[nodiscard]] double calculateMaintenanceCost() const override;

    [[nodiscard]] double getEngineDisplacement() const;
    [[nodiscard]] bool getHasSidecar() const;

    void attachSidecar();

};

#endif // MOTORCYCLE_H
