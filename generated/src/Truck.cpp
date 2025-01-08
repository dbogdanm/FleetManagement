#include "Truck.h"
#include <iostream>
#include <utility>
#include <sstream>

/**
 * @brief Constructor for Truck.
 * @param vin Vehicle Identification Number.
 * @param model Model of the truck.
 * @param kilometers Kilometers driven by the truck.
 * @param brand Brand of the truck.
 * @param loadCapacity Load capacity in tons.
 * @param fuelEfficiency Fuel efficiency in liters per 100 kilometers.
 */
Truck::Truck(int vin, const std::string& model, int kilometers,
             const std::string& brand, double loadCapacity, double fuelEfficiency,
             int brakeHealth, int tirePressure, int engineHealth,
             bool safetySystemsFunctional, int electronicSystemsHealth)
    : Vehicle(vin, model, kilometers, brand, brakeHealth, tirePressure, engineHealth,
              safetySystemsFunctional, electronicSystemsHealth),
      loadCapacity(loadCapacity),
      fuelEfficiency(fuelEfficiency)
{
}


/**
 * @brief Copy constructor for Truck.
 * @param other Another Truck object to copy from.
 */
Truck::Truck(const Truck& other)
    : Vehicle(other),
      loadCapacity(other.loadCapacity),
      fuelEfficiency(other.fuelEfficiency)
{
}

/**
 * @brief Copy assignment operator using copy-and-swap idiom.
 * @param other Another Truck object to assign from.
 * @return Reference to the current object.
 */
// Truck& Truck::operator=(Truck other)
// {
//     swap(*this, other);
//     return *this;
// }

/**
 * @brief Swaps two Truck objects.
 * @param first First Truck object.
 * @param second Second Truck object.
 *
 * Exchanges the load capacity, fuel efficiency, and base attributes between two trucks.
 */
void swap(Truck& first, Truck& second) noexcept
{
    first.swapBase(second);
    std::swap(first.loadCapacity, second.loadCapacity);
    std::swap(first.fuelEfficiency, second.fuelEfficiency);
}

/**
 * @brief Displays truck details.
 *
 * Prints VIN, model, kilometers, brand, load capacity, and fuel efficiency.
 */
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

/**
 * @brief Performs maintenance on the truck.
 *
 * Calculates and displays the maintenance cost.
 */
void Truck::performMaintenance()
{
    std::cout << "[Truck] Performing advanced maintenance for VIN " << vin << "...\n";

    double cost = calculateMaintenanceCost();
    std::cout << "Maintenance cost for this Truck is about: " << cost << " RON\n";
}

/**
 * @brief Creates a clone of the truck.
 * @return A unique pointer to the cloned Truck object.
 */
std::unique_ptr<Vehicle> Truck::clone() const
{
    return std::make_unique<Truck>(*this);
}

/**
 * @brief Calculates the maintenance cost for the truck.
 * @return The calculated maintenance cost.
 */
double Truck::calculateMaintenanceCost() const
{
    double baseCost = 400.0;
    double costPerKm = 0.07;
    double loadFactor = loadCapacity * 10.0;
    return baseCost + (kilometers * costPerKm) + loadFactor;
}

/**
 * @brief Retrieves the load capacity of the truck.
 * @return Load capacity in tons.
 */
double Truck::getLoadCapacity() const
{
    return loadCapacity;
}

/**
 * @brief Retrieves the fuel efficiency of the truck.
 * @return Fuel efficiency in liters per 100 kilometers.
 */
double Truck::getFuelEfficiency() const
{
    return fuelEfficiency;
}

/**
 * @brief Increases the load capacity of the truck.
 * @param extraTons Number of extra tons to add to the load capacity.
 */
void Truck::increaseLoadCapacity(double extraTons)
{
    loadCapacity += extraTons;
    std::cout << "[Truck] VIN " << vin << ": new load capacity is " << loadCapacity << " tons.\n";
}

/**
 * @brief Optimizes resource allocation for the truck.
 * @return A pair containing a strategy description and an efficiency score.
 *
 * Strategy depends on load capacity, fuel efficiency, and kilometers driven.
 */
std::pair<std::string, double> Truck::optimizeResourceAllocation() const
{
    double efficiencyScore = (loadCapacity / fuelEfficiency) * (kilometers + 1);
    std::string strategy = (loadCapacity > 20.0) ?
                           "Use for long-distance heavy cargo routes." :
                           "Assign to regional delivery tasks.";
    return {strategy, efficiencyScore};
}


std::string Truck::performSafetyInspection() const
{
    std::ostringstream report;
    report << "[Truck Safety Inspection Report]\n";
    report << "VIN: " << vin << "\n";
    report << "Model: " << model << "\n";
    report << "Brand: " << brand << "\n";
    report << "Brake Health: " << brakeHealth << "%\n";
    report << "Tire Pressure: " << tirePressure << " psi\n";
    report << "Engine Health: " << engineHealth << "%\n";
    report << "Safety Systems: " << (safetySystemsFunctional ? "Functional" : "Non-functional") << "\n";
    report << "Electronics Health: " << electronicSystemsHealth << "%\n";
    report << "Load Capacity: " << loadCapacity << " tons\n";
    report << "Fuel Efficiency: " << fuelEfficiency << " L/100km\n";
    report << "Overall Status: " << (safetySystemsFunctional && brakeHealth > 70 && engineHealth > 70 ? "PASS" : "FAIL") << "\n";

    return report.str();
}
