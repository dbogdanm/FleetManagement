#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <memory>
#include <utility>

/**
 * @class Vehicle
 * @brief Abstract base class representing a generic vehicle.
 *
 * The Vehicle class serves as a base class for specific vehicle types such as
 * buses, motorcycles, and trucks. It includes common attributes like VIN,
 * model, kilometers driven, and brand. The class enforces implementation of
 * specific methods in derived classes through pure virtual functions.
 */
class Vehicle
{
protected:
    /**
     * @brief The Vehicle Identification Number (VIN) of the vehicle.
     */
    int vin;

    /**
     * @brief The model name of the vehicle.
     */
    std::string model;

    /**
     * @brief The total kilometers driven by the vehicle.
     */
    int kilometers;

    /**
     * @brief The brand of the vehicle.
     */
    std::string brand;

public:
    /**
     * @brief Constructs a Vehicle with the specified attributes.
     */
    Vehicle(int vin, std::string model, int kilometers, std::string brand);

    /**
     * @brief Copy constructor for Vehicle.
     */
    Vehicle(const Vehicle& other);

    /**
     * @brief Virtual destructor for Vehicle.
     */
    virtual ~Vehicle() = default;

    /**
     * @brief Displays detailed information about the vehicle (pure virtual).
     */
    virtual void display() const = 0;

    /**
     * @brief Performs maintenance on the vehicle (pure virtual).
     */
    virtual void performMaintenance() = 0;

    /**
     * @brief Creează un obiect clonat al vehiculului curent (pure virtual).
     */
    [[nodiscard]] virtual std::unique_ptr<Vehicle> clone() const = 0;

    /**
     * @brief Returnează costul de mentenanță al vehiculului (pure virtual).
     *
     * Am adăugat această funcție deoarece în VehicleService apare
     * `vehicle->calculateMaintenanceCost()`.
     */
    [[nodiscard]] virtual double calculateMaintenanceCost() const = 0;

    /**
     * @brief Displays basic information about the vehicle.
     */
    void showInfo() const;

    /**
     * @brief Gets the VIN of the vehicle.
     */
    [[nodiscard]] int getVin() const;

protected:
    /**
     * @brief Swaps the base attributes of two Vehicle objects (folosit în copy-and-swap).
     */
    void swapBase(Vehicle& other) noexcept;

public:
    /**
     * @brief Deleted assignment operator for Vehicle.
     */
    Vehicle& operator=(const Vehicle& other) = delete;
};

#endif // VEHICLE_H
