#include "Bus.h"
#include <iostream>
#include <utility>

Bus::Bus(int vin, const std::string& model, int kilometers,
         const std::string& brand, int seatingCapacity, bool hasWiFi)
    : Vehicle(vin, model, kilometers, brand),
      seatingCapacity(seatingCapacity),
      hasWiFi(hasWiFi)
{
}

Bus::Bus(const Bus& other)
    : Vehicle(other),
      seatingCapacity(other.seatingCapacity),
      hasWiFi(other.hasWiFi)
{
}

Bus& Bus::operator=(Bus other)
{
    swap(*this, other);
    return *this;
}

void swap(Bus& first, Bus& second) noexcept
{
    first.swapBase(second);
    std::swap(first.seatingCapacity, second.seatingCapacity);
    std::swap(first.hasWiFi, second.hasWiFi);
}

void Bus::display() const
{
    std::cout << "[Bus] VIN: " << vin
              << ", Model: " << model
              << ", Kilometers: " << kilometers
              << ", Brand: " << brand
              << ", Seating Capacity: " << seatingCapacity
              << ", WiFi: " << (hasWiFi ? "Yes" : "No") << std::endl;
}

void Bus::performMaintenance()
{
    std::cout << "[Bus] Performing advanced maintenance for VIN " << vin << "...\n";
    // Mai multă logică, de ex:
    double cost = calculateMaintenanceCost();
    std::cout << "Maintenance cost for this Bus is approximately: " << cost << " RON\n";
}

std::unique_ptr<Vehicle> Bus::clone() const
{
    return std::make_unique<Bus>(*this);
}

double Bus::calculateMaintenanceCost() const
{
    // Exemplu de calcul ipotetic al costului de mentenanță
    double baseCost = 300.0;        // cost de bază
    double costPerKm = 0.05;        // cost per kilometru
    double wifiExtra = hasWiFi ? 50.0 : 0.0; // cost suplimentar pentru WiFi
    return baseCost + (kilometers * costPerKm) + wifiExtra;
}

int Bus::getSeatingCapacity() const
{
    return seatingCapacity;
}

bool Bus::getHasWiFi() const
{
    return hasWiFi;
}

void Bus::upgradeWiFi()
{
    if (!hasWiFi) {
        hasWiFi = true;
        std::cout << "[Bus] WiFi upgraded for VIN " << vin << std::endl;
    } else {
        std::cout << "[Bus] VIN " << vin << " already has WiFi.\n";
    }
}

void Bus::increaseSeatingCapacity(int extraSeats)
{
    seatingCapacity += extraSeats;
    std::cout << "[Bus] VIN " << vin
              << ": seating capacity is now " << seatingCapacity << std::endl;
}