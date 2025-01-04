#include "VehicleService.h"
#include "Truck.h"
#include <memory>
#include <iostream>
#include <utility>

VehicleService::VehicleService(Vehicle* vehicle)
    : vehicle(vehicle)
{
}

VehicleService::VehicleService(const VehicleService& other)
    : vehicle(other.vehicle ? other.vehicle->clone().release() : nullptr)
{
}

VehicleService& VehicleService::operator=(VehicleService other)
{
    swap(*this, other);
    return *this;
}

VehicleService::~VehicleService()
{
    delete vehicle;
}

void swap(VehicleService& first, VehicleService& second) noexcept
{
    using std::swap;
    swap(first.vehicle, second.vehicle);
}

double VehicleService::GetCost() const
{
    if (!vehicle) {
        return 0.0;
    }
    return vehicle->calculateMaintenanceCost();
}

std::ostream& operator<<(std::ostream& os, const VehicleService& service)
{
    if (service.vehicle)
        os << "Vehicle Service Cost: " << service.GetCost();
    else
        os << "No vehicle assigned.";
    return os;
}

void VehicleService::GetTrailerCapacity()
{
    // În codul original se vedea un dynamic_cast<Truck> pe pointerul vehicle, dar era un shared_ptr.
    // Aici, avem doar un pointer clasic, așa că facem:
    auto* truck = dynamic_cast<Truck*>(vehicle);
    if (truck)
    {
        // Metodă fictivă, se poate folosi getLoadCapacity() daca vrei să vezi ceva concret.
        std::cout << "Truck load capacity is: " << truck->getLoadCapacity() << " tons\n";
    }
    else
    {
        std::cout << "Vehicle is not of type Truck.\n";
    }
}
