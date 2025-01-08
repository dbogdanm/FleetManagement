#include "Bus.h"
#include <iostream>
#include <utility>
#include <sstream>

/**
 * @brief Constructor for Bus.
 * @param vin Vehicle Identification Number.
 * @param model Model of the bus.
 * @param kilometers Kilometers driven by the bus.
 * @param brand Brand of the bus.
 * @param seatingCapacity Number of passenger seats.
 * @param hasWiFi Availability of WiFi on the bus.
 */

Bus::Bus(int vin, const std::string& model, int kilometers,
         const std::string& brand, int seatingCapacity, bool hasWiFi,
         int brakeHealth, int tirePressure, int engineHealth,
         bool safetySystemsFunctional, int electronicSystemsHealth)
    : Vehicle(vin, model, kilometers, brand, brakeHealth, tirePressure, engineHealth,
              safetySystemsFunctional, electronicSystemsHealth),
      seatingCapacity(seatingCapacity),
      hasWiFi(hasWiFi)
{
}


/**
 * @brief Copy constructor for Bus.
 * @param other Another Bus object to copy from.
 */
Bus::Bus(const Bus& other)
    : Vehicle(other),
      seatingCapacity(other.seatingCapacity),
      hasWiFi(other.hasWiFi)
{
}

/**
 * @brief Copy assignment operator using copy-and-swap idiom.
 * @param other Another Bus object to assign from.
 * @return Reference to the current object.
 */
// Bus& Bus::operator=(Bus other)
// {
//     swap(*this, other);
//     return *this;
// }

/**
 * @brief Swaps two Bus objects.
 * @param first First Bus object.
 * @param second Second Bus object.
 */
void swap(Bus& first, Bus& second) noexcept
{
    first.swapBase(second);
    std::swap(first.seatingCapacity, second.seatingCapacity);
    std::swap(first.hasWiFi, second.hasWiFi);
}

/**
 * @brief Displays Bus details.
 * Prints information about VIN, model, kilometers, brand, seating capacity, and WiFi availability.
 */
void Bus::display() const
{
    std::cout << "[Bus] VIN: " << vin
              << ", Model: " << model
              << ", Kilometers: " << kilometers
              << ", Brand: " << brand
              << ", Seating Capacity: " << seatingCapacity
              << ", WiFi: " << (hasWiFi ? "Yes" : "No") << std::endl;
}

/**
 * @brief Performs maintenance on the Bus.
 * Prints maintenance details, including calculated cost.
 */
void Bus::performMaintenance()
{
    std::cout << "[Bus] Performing advanced maintenance for VIN " << vin << "...\n";
    double cost = calculateMaintenanceCost();
    std::cout << "Maintenance cost for this Bus is approximately: " << cost << " RON\n";
}

/**
 * @brief Creates a clone of the current Bus object.
 * @return A unique pointer to the cloned Bus object.
 */
std::unique_ptr<Vehicle> Bus::clone() const
{
    return std::make_unique<Bus>(*this);
}

/**
 * @brief Calculates the maintenance cost for the Bus.
 * @return The calculated maintenance cost.
 */
double Bus::calculateMaintenanceCost() const
{
    double baseCost = 300.0;
    double costPerKm = 0.05;
    double wifiExtra = hasWiFi ? 50.0 : 0.0;
    return baseCost + (kilometers * costPerKm) + wifiExtra;
}

/**
 * @brief Gets the seating capacity of the Bus.
 * @return Seating capacity as an integer.
 */
int Bus::getSeatingCapacity() const
{
    return seatingCapacity;
}

/**
 * @brief Checks if the Bus has WiFi.
 * @return True if the Bus has WiFi, false otherwise.
 */
bool Bus::getHasWiFi() const
{
    return hasWiFi;
}

/**
 * @brief Upgrades the WiFi on the Bus.
 *
 * Enables WiFi if it is not already available.
 */
void Bus::upgradeWiFi()
{
    if (!hasWiFi) {
        hasWiFi = true;
        std::cout << "[Bus] WiFi upgraded for VIN " << vin << std::endl;
    } else {
        std::cout << "[Bus] VIN " << vin << " already has WiFi.\n";
    }
}

/**
 * @brief Increases the seating capacity of the Bus.
 * @param extraSeats Number of additional seats to add.
 */
void Bus::increaseSeatingCapacity(int extraSeats)
{
    seatingCapacity += extraSeats;
    std::cout << "[Bus] VIN " << vin
              << ": seating capacity is now " << seatingCapacity << std::endl;
}

/**
 * @brief Optimizes resource allocation for the Bus.
 * @return A pair containing a strategy description and an efficiency score.
 *
 * Strategy depends on seating capacity, and the efficiency score factors in
 * seating capacity, kilometers, and WiFi availability.
 */
std::pair<std::string, double> Bus::optimizeResourceAllocation() const
{
    double efficiencyScore = seatingCapacity / (kilometers + 1) * (hasWiFi ? 1.1 : 1.0);
    std::string strategy = (seatingCapacity > 40) ?
                           "Assign to high-demand city routes." :
                           "Use on low-demand suburban routes.";

    return {strategy, efficiencyScore};
}



std::string Bus::performSafetyInspection() const
{
    std::ostringstream report;
    report << "[Bus Safety Inspection Report]\n";
    report << "VIN: " << vin << "\n";
    report << "Model: " << model << "\n";
    report << "Brand: " << brand << "\n";
    report << "Brake Health: " << brakeHealth << "%\n";
    report << "Tire Pressure: " << tirePressure << " psi\n";
    report << "Engine Health: " << engineHealth << "%\n";
    report << "Safety Systems: " << (safetySystemsFunctional ? "Functional" : "Non-functional") << "\n";
    report << "Electronics Health: " << electronicSystemsHealth << "%\n";
    report << "Seating Capacity: " << seatingCapacity << "\n";
    report << "WiFi: " << (hasWiFi ? "Available" : "Unavailable") << "\n";
    report << "Overall Status: " << (safetySystemsFunctional && brakeHealth > 70 && engineHealth > 70 ? "PASS" : "FAIL") << "\n";

    return report.str();
}
