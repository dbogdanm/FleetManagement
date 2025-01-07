#include "VehicleService.h"
#include "Truck.h"
#include <memory>
#include <iostream>
#include <utility>

/**
 * @brief Constructor for VehicleService.
 * @param vehicle Pointer to a Vehicle object.
 *
 * Initializes the service with a given vehicle.
 */
VehicleService::VehicleService(Vehicle* vehicle)
    : vehicle(vehicle)
{
}

/**
 * @brief Copy constructor for VehicleService.
 * @param other Another VehicleService object to copy from.
 *
 * Creates a deep copy by cloning the assigned vehicle.
 */
VehicleService::VehicleService(const VehicleService& other)
    : vehicle(other.vehicle ? other.vehicle->clone().release() : nullptr)
{
}

/**
 * @brief Copy assignment operator using copy-and-swap idiom.
 * @param other Another VehicleService object to assign from.
 * @return Reference to the current object.
 */
VehicleService& VehicleService::operator=(VehicleService other)
{
    swap(*this, other);
    return *this;
}

/**
 * @brief Destructor for VehicleService.
 *
 * Cleans up the dynamically allocated vehicle object.
 */
VehicleService::~VehicleService()
{
    delete vehicle;
}

/**
 * @brief Swaps two VehicleService objects.
 * @param first First VehicleService object.
 * @param second Second VehicleService object.
 *
 * Exchanges the assigned vehicle pointers between two objects.
 */
void swap(VehicleService& first, VehicleService& second) noexcept
{
    using std::swap;
    swap(first.vehicle, second.vehicle);
}

/**
 * @brief Calculates the maintenance cost of the assigned vehicle.
 * @return Maintenance cost as a double.
 *
 * Returns 0.0 if no vehicle is assigned.
 */
double VehicleService::GetCost() const
{
    if (!vehicle) {
        return 0.0;
    }
    return vehicle->calculateMaintenanceCost();
}

/**
 * @brief Overloaded stream operator for VehicleService.
 * @param os Output stream object.
 * @param service VehicleService object to print.
 * @return Reference to the output stream.
 *
 * Prints the maintenance cost or indicates if no vehicle is assigned.
 */
std::ostream& operator<<(std::ostream& os, const VehicleService& service)
{
    if (service.vehicle)
        os << "Vehicle Service Cost: " << service.GetCost();
    else
        os << "No vehicle assigned.";
    return os;
}

/**
 * @brief Retrieves the trailer capacity if the vehicle is a Truck.
 *
 * Uses `dynamic_cast` to check if the vehicle is of type Truck and
 * displays its load capacity. Otherwise, prints an error message.
 */
void VehicleService::GetTrailerCapacity()
{
    auto* truck = dynamic_cast<Truck*>(vehicle);
    if (truck)
    {
        std::cout << "Truck load capacity is: " << truck->getLoadCapacity() << " tons\n";
    }
    else
    {
        std::cout << "Vehicle is not of type Truck.\n";
    }
}
