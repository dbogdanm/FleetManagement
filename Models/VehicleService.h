#ifndef VEHICLESERVICE_H
#define VEHICLESERVICE_H

#include "Vehicle.h"
#include <iostream>
#include <memory>

class VehicleService
{
private:
    Vehicle* vehicle;

public:
    VehicleService(Vehicle* vehicle);
    VehicleService(const VehicleService& other);
    VehicleService& operator=(VehicleService other);
    ~VehicleService();

    friend void swap(VehicleService& first, VehicleService& second) noexcept;

    double GetCost() const;

    friend std::ostream& operator<<(std::ostream& os, const VehicleService& service);

    /**
     * @brief Metodă care ar trebui să fie specifică pentru Truck.
     *        Using dynamic_cast.
     */
    void GetTrailerCapacity();
};

#endif // VEHICLESERVICE_H
