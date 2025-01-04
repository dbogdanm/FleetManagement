#include "Truck.h"
#include <iostream>
#include <utility>

Truck::Truck(int vin, const std::string& model, int kilometers,
             const std::string& brand, double loadCapacity, double fuelEfficiency)
    : Vehicle(vin, model, kilometers, brand),
      loadCapacity(loadCapacity),
      fuelEfficiency(fuelEfficiency)
{
}

Truck::Truck(const Truck& other)
    : Vehicle(other),
      loadCapacity(other.loadCapacity),
      fuelEfficiency(other.fuelEfficiency)
{
}

Truck& Truck::operator=(Truck other)
{
    swap(*this, other);
    return *this;
}

void swap(Truck& first, Truck& second) noexcept
{
    first.swapBase(second);
    std::swap(first.loadCapacity, second.loadCapacity);
    std::swap(first.fuelEfficiency, second.fuelEfficiency);
}

void Truck::display() const
{
    std::cout << "[Truck] VIN: " << vin
              << ", Model: " << model
              << ", Kilometers: " << kilometers
              << ", Brand: " << brand
              << ", Load Capacity: " << loadCapacity << " tons"
              << ", Fuel Efficiency: " << fuelEfficiency << " L/100km"
              << std::endl;
}

void Truck::performMaintenance()
{
    std::cout << "[Truck] Performing advanced maintenance for VIN " << vin << "...\n";
    // Exemplu de logică
    double cost = calculateMaintenanceCost();
    std::cout << "Maintenance cost for this Truck is about: " << cost << " RON\n";
}

std::unique_ptr<Vehicle> Truck::clone() const
{
    return std::make_unique<Truck>(*this);
}

double Truck::calculateMaintenanceCost() const
{
    // Exemplu de calcul
    double baseCost = 400.0;
    double costPerKm = 0.07;
    double loadFactor = loadCapacity * 10.0;
    return baseCost + (kilometers * costPerKm) + loadFactor;
}

double Truck::getLoadCapacity() const
{
    return loadCapacity;
}

double Truck::getFuelEfficiency() const
{
    return fuelEfficiency;
}

void Truck::increaseLoadCapacity(double extraTons)
{
    loadCapacity += extraTons;
    std::cout << "[Truck] VIN " << vin << ": new load capacity is " << loadCapacity << " tons.\n";
}