#include "Motorcycle.h"
#include <iostream>
#include <utility>

Motorcycle::Motorcycle(int vin, const std::string& model, int kilometers,
                       const std::string& brand, double engineDisplacement, bool hasSidecar)
    : Vehicle(vin, model, kilometers, brand),
      engineDisplacement(engineDisplacement),
      hasSidecar(hasSidecar)
{
}

Motorcycle::Motorcycle(const Motorcycle& other)
    : Vehicle(other),
      engineDisplacement(other.engineDisplacement),
      hasSidecar(other.hasSidecar)
{
}

Motorcycle& Motorcycle::operator=(Motorcycle other)
{
    swap(*this, other);
    return *this;
}

void swap(Motorcycle& first, Motorcycle& second) noexcept
{
    first.swapBase(second);
    std::swap(first.engineDisplacement, second.engineDisplacement);
    std::swap(first.hasSidecar, second.hasSidecar);
}

void Motorcycle::display() const
{
    std::cout << "[Motorcycle] VIN: " << vin
              << ", Model: " << model
              << ", Kilometers: " << kilometers
              << ", Brand: " << brand
              << ", Engine Displacement: " << engineDisplacement << "cc"
              << ", Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
}

void Motorcycle::performMaintenance()
{
    std::cout << "[Motorcycle] Performing advanced maintenance for VIN " << vin << "...\n";

    double cost = calculateMaintenanceCost();
    std::cout << "Maintenance cost for this Motorcycle is about: " << cost << " RON\n";
}

std::unique_ptr<Vehicle> Motorcycle::clone() const
{
    return std::make_unique<Motorcycle>(*this);
}

double Motorcycle::calculateMaintenanceCost() const
{

    double baseCost = 150.0;
    double costPerKm = 0.03;
    double sidecarExtra = hasSidecar ? 20.0 : 0.0;
    return baseCost + (kilometers * costPerKm) + sidecarExtra;
}

double Motorcycle::getEngineDisplacement() const
{
    return engineDisplacement;
}

void Motorcycle::attachSidecar()
{
    if (!hasSidecar) {
        hasSidecar = true;
        std::cout << "[Motorcycle] Sidecar attached for VIN " << vin << std::endl;
    } else {
        std::cout << "[Motorcycle] VIN " << vin << " already has a sidecar.\n";
    }
}
bool Motorcycle::getHasSidecar() const
{
    return hasSidecar;
}
