#ifndef VEHICLESERVICE_H
#define VEHICLESERVICE_H

#include "Vehicle.h"
#include <iostream>
#include <memory>

/**
 * @class VehicleService
 * @brief Manages vehicle maintenance and related operations.
 */
class VehicleService
{
private:
    Vehicle* vehicle; ///< Pointer to the associated vehicle.

public:
    VehicleService(Vehicle* vehicle); ///< Constructor.
    VehicleService(const VehicleService& other); ///< Copy constructor.
    VehicleService& operator=(VehicleService other); ///< Copy assignment operator.
    ~VehicleService(); ///< Destructor.

    friend void swap(VehicleService& first, VehicleService& second) noexcept; ///< Swap two services.

    double GetCost() const; ///< Get maintenance cost.

    friend std::ostream& operator<<(std::ostream& os, const VehicleService& service); ///< Output service details.

    void GetTrailerCapacity(); ///< Get trailer capacity if the vehicle is a truck.
};

#endif // VEHICLESERVICE_H
