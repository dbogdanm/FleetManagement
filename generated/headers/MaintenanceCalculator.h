#ifndef MAINTENANCE_CALCULATOR_H
#define MAINTENANCE_CALCULATOR_H

#include <iostream>

/**
 * @brief Calculates and displays the maintenance cost of a vehicle.
 *
 * @tparam T Type of the vehicle object.
 * @param vehicle A reference to the vehicle object.
 *
 * Prints the VIN and calculated maintenance cost of the vehicle.
 */
template<typename T>
void calculateAndDisplayCost(const T& vehicle)
{
    std::cout << "Maintenance cost for vehicle with VIN " << vehicle.getVin()
              << ": " << vehicle.calculateMaintenanceCost() << " RON" << std::endl;
}

#endif // MAINTENANCE_CALCULATOR_H
