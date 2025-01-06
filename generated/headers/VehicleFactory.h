#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H

#include <memory>
#include <string>
#include "Bus.h"
#include "Truck.h"
#include "Motorcycle.h"

class VehicleFactory {
public:
    static std::unique_ptr<Vehicle> createVehicle(const std::string& type);
};

#endif // VEHICLE_FACTORY_H
