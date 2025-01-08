#include "Motorcycle.h"
#include <iostream>
#include <utility>
#include <sstream>

/**
 * @brief Constructor for Motorcycle.
 * @param vin Vehicle Identification Number.
 * @param model Model of the motorcycle.
 * @param kilometers Kilometers driven by the motorcycle.
 * @param brand Brand of the motorcycle.
 * @param engineDisplacement Engine displacement in cubic centimeters (cc).
 * @param hasSidecar Indicates if the motorcycle has a sidecar.
 */
Motorcycle::Motorcycle(int vin, const std::string& model, int kilometers,
                       const std::string& brand, double engineDisplacement, bool hasSidecar,
                       int brakeHealth, int tirePressure, int engineHealth,
                       bool safetySystemsFunctional, int electronicSystemsHealth)
    : Vehicle(vin, model, kilometers, brand, brakeHealth, tirePressure, engineHealth,
              safetySystemsFunctional, electronicSystemsHealth),
      engineDisplacement(engineDisplacement),
      hasSidecar(hasSidecar)
{
}


/**
 * @brief Copy constructor for Motorcycle.
 * @param other Another Motorcycle object to copy from.
 */
Motorcycle::Motorcycle(const Motorcycle& other)
    : Vehicle(other),
      engineDisplacement(other.engineDisplacement),
      hasSidecar(other.hasSidecar)
{
}

/**
 * @brief Copy assignment operator using copy-and-swap idiom.
 * @param other Another Motorcycle object to assign from.
 * @return Reference to the current object.
 */
// Motorcycle& Motorcycle::operator=(Motorcycle other)
// {
//     swap(*this, other);
//     return *this;
// }

/**
 * @brief Swaps two Motorcycle objects.
 * @param first First Motorcycle object.
 * @param second Second Motorcycle object.
 */
void swap(Motorcycle& first, Motorcycle& second) noexcept
{
    first.swapBase(second);
    std::swap(first.engineDisplacement, second.engineDisplacement);
    std::swap(first.hasSidecar, second.hasSidecar);
}

/**
 * @brief Displays motorcycle details.
 *
 * Prints VIN, model, kilometers, brand, engine displacement, and sidecar status.
 */
void Motorcycle::display() const
{
    std::cout << "[Motorcycle] VIN: " << vin
              << ", Model: " << model
              << ", Kilometers: " << kilometers
              << ", Brand: " << brand
              << ", Engine Displacement: " << engineDisplacement << "cc"
              << ", Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
}

/**
 * @brief Performs maintenance on the motorcycle.
 *
 * Calculates and displays the maintenance cost.
 */
void Motorcycle::performMaintenance()
{
    std::cout << "[Motorcycle] Performing advanced maintenance for VIN " << vin << "...\n";
    double cost = calculateMaintenanceCost();
    std::cout << "Maintenance cost for this Motorcycle is about: " << cost << " RON\n";
}

/**
 * @brief Creates a clone of the motorcycle.
 * @return A unique pointer to the cloned Motorcycle object.
 */
std::unique_ptr<Vehicle> Motorcycle::clone() const
{
    return std::make_unique<Motorcycle>(*this);
}

/**
 * @brief Calculates the maintenance cost for the motorcycle.
 * @return The calculated maintenance cost.
 */
double Motorcycle::calculateMaintenanceCost() const
{
    double baseCost = 150.0;
    double costPerKm = 0.03;
    double sidecarExtra = hasSidecar ? 20.0 : 0.0;
    return baseCost + (kilometers * costPerKm) + sidecarExtra;
}

/**
 * @brief Retrieves the engine displacement.
 * @return Engine displacement in cubic centimeters (cc).
 */
double Motorcycle::getEngineDisplacement() const
{
    return engineDisplacement;
}

/**
 * @brief Attaches a sidecar to the motorcycle.
 *
 * If a sidecar is not already attached, it adds one.
 */
void Motorcycle::attachSidecar()
{
    if (!hasSidecar) {
        hasSidecar = true;
        std::cout << "[Motorcycle] Sidecar attached for VIN " << vin << std::endl;
    } else {
        std::cout << "[Motorcycle] VIN " << vin << " already has a sidecar.\n";
    }
}

/**
 * @brief Checks if the motorcycle has a sidecar.
 * @return True if it has a sidecar, false otherwise.
 */
bool Motorcycle::getHasSidecar() const
{
    return hasSidecar;
}

/**
 * @brief Optimizes resource allocation for the motorcycle.
 * @return A pair containing a strategy description and an efficiency score.
 *
 * Determines an efficiency score based on kilometers and whether it has a sidecar.
 */
std::pair<std::string, double> Motorcycle::optimizeResourceAllocation() const
{
    double efficiencyScore = (1000.0 / (kilometers + 1)) * (hasSidecar ? 0.9 : 1.1);
    std::string strategy = (hasSidecar) ?
                           "Use for medium package delivery." :
                           "Assign to express delivery tasks.";
    return {strategy, efficiencyScore};
}
#include <sstream>

std::string Motorcycle::performSafetyInspection() const {
    std::ostringstream report;
    report << "[Motorcycle Safety Inspection Report]\n";
    report << "VIN: " << vin << "\n";
    report << "Model: " << model << "\n";
    report << "Brand: " << brand << "\n";
    report << "Brake Health: " << brakeHealth << "%\n";
    report << "Tire Pressure: " << tirePressure << " psi\n";
    report << "Engine Health: " << engineHealth << "%\n";
    report << "Safety Systems: " << (safetySystemsFunctional ? "Functional" : "Non-functional") << "\n";
    report << "Electronics Health: " << electronicSystemsHealth << "%\n";
    report << "Engine Displacement: " << engineDisplacement << " cc\n";
    report << "Sidecar: " << (hasSidecar ? "Attached" : "Not Attached") << "\n";
    report << "Overall Status: " << (safetySystemsFunctional && brakeHealth > 70 && engineHealth > 70 ? "PASS" : "FAIL") << "\n";

    return report.str();
}
