#ifndef MAINTENANCE_CALCULATOR_H
#define MAINTENANCE_CALCULATOR_H

#include <iostream>

template<typename T>
void calculateAndDisplayCost(const T& vehicle) {
    std::cout << "Maintenance cost for vehicle with VIN " << vehicle.getVin()
              << ": " << vehicle.calculateMaintenanceCost() << " RON" << std::endl;
}

#endif // MAINTENANCE_CALCULATOR_H
