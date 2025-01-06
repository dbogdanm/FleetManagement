#include "../generated/headers/VehicleFactory.h"
#include <stdexcept>

std::unique_ptr<Vehicle> VehicleFactory::createVehicle(const std::string& type) {
    if (type == "Bus") {
        return std::make_unique<Bus>(201, "CityBus", 10000, "Mercedes", 50, true);
    } else if (type == "Truck") {
        return std::make_unique<Truck>(202, "FreightTruck", 5000, "Volvo", 15.0, 8.5);
    } else if (type == "Motorcycle") {
        return std::make_unique<Motorcycle>(203, "Speedster", 2000, "Yamaha", 600.0, false);
    }
    throw std::invalid_argument("Unknown vehicle type");
}
