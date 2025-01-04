#include "Vehicle.h"

/**
 * @brief Vehicle constructor
 */
Vehicle::Vehicle(int vin, std::string model, int kilometers, std::string brand)
    : vin(vin), model(std::move(model)), kilometers(kilometers), brand(std::move(brand)) {}

/**
 * @brief Vehicle copy constructor
 */
Vehicle::Vehicle(const Vehicle& other)
    : vin(other.vin),
      model(other.model),
      kilometers(other.kilometers),
      brand(other.brand)
{
}

/**
 * @brief Afișează informații de bază (non-virtual).
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
 * @brief Returnează VIN.
 */
int Vehicle::getVin() const
{
    return vin;
}

/**
 * @brief Swap pentru atributele de bază ale clasei Vehicle.
 */
void Vehicle::swapBase(Vehicle& other) noexcept
{
    using std::swap;
    swap(vin, other.vin);
    swap(model, other.model);
    swap(kilometers, other.kilometers);
    swap(brand, other.brand);
}
