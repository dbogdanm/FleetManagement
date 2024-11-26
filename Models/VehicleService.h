#ifndef VEHICLESERVICE_H
#define VEHICLESERVICE_H

#include "Vehicle.h"
#include <iostream>
#include <memory>
#include <utility>
#include "Truck.h"

/**
 * @class VehicleService
 * @brief Manages the maintenance and service-related operations for a vehicle.
 *
 * The VehicleService class encapsulates a single vehicle and provides
 * functionality for calculating maintenance costs, cloning vehicles, and performing
 * specific operations for truck-type vehicles.
 */
class VehicleService
{
private:
    /**
     * @brief Pointer to the vehicle being serviced.
     */
    Vehicle* vehicle;

public:
    /**
     * @brief Constructs a VehicleService with the specified vehicle.
     *
     * @param vehicle A pointer to the vehicle to be serviced.
     */
    VehicleService(Vehicle* vehicle) : vehicle(vehicle) {}

    /**
     * @brief Calculates the maintenance cost of the vehicle.
     *
     * Delegates the cost calculation to the associated vehicle.
     *
     * @return The calculated maintenance cost.
     */
    double GetCost() const
    {
        return vehicle->calculateMaintenanceCost();
    }

    /**
     * @brief Copy constructor for VehicleService.
     *
     * Creates a deep copy of the VehicleService object, cloning the associated vehicle.
     *
     * @param other The VehicleService object to copy.
     */
    VehicleService(const VehicleService& other)
        : vehicle(other.vehicle ? other.vehicle->clone() : nullptr) {}

    /**
     * @brief Copy assignment operator for VehicleService.
     *
     * Uses the copy-and-swap idiom to assign one VehicleService object to another.
     *
     * @param other The VehicleService object to assign from.
     * @return A reference to the assigned VehicleService object.
     */
    VehicleService& operator=(VehicleService other)
    {
        swap(*this, other);
        return *this;
    }

    /**
     * @brief Destroys the VehicleService object and releases the associated vehicle.
     */
    ~VehicleService()
    {
        delete vehicle;
    }

    /**
     * @brief Swaps the contents of two VehicleService objects.
     *
     * Used for implementing the copy-and-swap idiom.
     *
     * @param first The first VehicleService object.
     * @param second The second VehicleService object.
     */
    friend void swap(VehicleService& first, VehicleService& second) noexcept
    {
        using std::swap;
        swap(first.vehicle, second.vehicle);
    }

    /**
     * @brief Outputs information about the vehicle service to an output stream.
     *
     * Displays the maintenance cost or indicates if no vehicle is assigned.
     *
     * @param os The output stream.
     * @param service The VehicleService object to output.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const VehicleService& service)
    {
        if (service.vehicle)
            os << "Vehicle Service Cost: " << service.GetCost();
        else
            os << "No vehicle assigned.";
        return os;
    }

    /**
     * @brief Retrieves the trailer capacity for truck-type vehicles.
     *
     * Uses dynamic casting to check if the associated vehicle is a truck.
     * Outputs the trailer capacity if the vehicle is a truck or indicates otherwise.
     */
    void GetTrailerCapacity()
    {
        std::shared_ptr<Truck> truck = std::dynamic_pointer_cast<Truck>(vehicle);
        if (truck)
        {
            std::cout << "Specific function for truck: " << truck->GetTrailerCapacity() << std::endl;
        }
        else
        {
            std::cout << "Vehicle is not of type truck." << std::endl;
        }
    }
};

#endif // VEHICLESERVICE_H
