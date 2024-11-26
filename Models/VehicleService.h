#ifndef VEHICLESERVICE_H
#define VEHICLESERVICE_H

#include "Vehicle.h"
#include <iostream>
#include <memory>
#include <utility>

#include "Truck.h"

class VehicleService
{
private:
    Vehicle* vehicle;

public:

    VehicleService(Vehicle* vehicle) : vehicle(vehicle) {}


    double GetCost() const
    {
        return vehicle->calculateMaintenanceCost();
    }


    VehicleService(const VehicleService& other)
        : vehicle(other.vehicle ? other.vehicle->clone() : nullptr) {}



    VehicleService& operator=(VehicleService other)
    {
        swap(*this, other);
        return *this;
    }


    ~VehicleService()
    {
        delete vehicle;
    }


    friend void swap(VehicleService& first, VehicleService& second) noexcept
    {
        using std::swap;
        swap(first.vehicle, second.vehicle);
    }


    friend std::ostream& operator<<(std::ostream& os, const VehicleService& service)
    {
        if (service.vehicle)
            os << "Vehicle Service Cost: " << service.GetCost();
        else
            os << "No vehicle assigned.";
        return os;
    }

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
