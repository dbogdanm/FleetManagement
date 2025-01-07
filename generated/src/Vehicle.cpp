#include "Vehicle.h"
#include <iostream>
#include <utility>

/**
 * @brief Constructor for Vehicle.
 * @param vin Vehicle Identification Number.
 * @param model Model of the vehicle.
 * @param kilometers Kilometers driven by the vehicle.
 * @param brand Brand of the vehicle.
 */
Vehicle::Vehicle(int vin, std::string model, int kilometers, std::string brand)
    : vin(vin), model(std::move(model)), kilometers(kilometers), brand(std::move(brand)) {}

/**
 * @brief Copy constructor for Vehicle.
 * @param other Another Vehicle object to copy from.
 */
Vehicle::Vehicle(const Vehicle& other)
    : vin(other.vin),
      model(other.model),
      kilometers(other.kilometers),
      brand(other.brand)
{
}

/**
 * @brief Displays basic vehicle information.
 *
 * Prints the vehicle's VIN, model, kilometers driven, and brand.
 */
void Vehicle::showInfo() const
{
    std::cout << "VIN: " << vin
              << ", Model: " << model
              << ", Kilometers: " << kilometers
              << ", Brand: " << brand
              << std::endl;
}

/**
 * @brief Retrieves the vehicle's VIN.
 * @return Vehicle Identification Number (VIN).
 */
int Vehicle::getVin() const
{
    return vin;
}

/**
 * @brief Swaps base attributes between two Vehicle objects.
 * @param other Another Vehicle object to swap attributes with.
 *
 * Exchanges the VIN, model, kilometers, and brand between two Vehicle objects.
 */
void Vehicle::swapBase(Vehicle& other) noexcept
{
    using std::swap;
    swap(vin, other.vin);
    swap(model, other.model);
    swap(kilometers, other.kilometers);
    swap(brand, other.brand);
}
