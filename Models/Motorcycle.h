#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

/**
 * @class Motorcycle
 * @brief Represents a motorcycle vehicle.
 */
class Motorcycle : public Vehicle
{
private:
    double engineDisplacement; ///< Engine displacement in cc.
    bool hasSidecar; ///< Indicates if the motorcycle has a sidecar.

public:
    Motorcycle(int vin, const std::string& model, int kilometers,
               const std::string& brand, double engineDisplacement, bool hasSidecar, int brakeHealth, int tirePressure, int engineHealth, bool safetySystemsFunctional, int electronicSystemsHealth); ///< Constructor.
    Motorcycle(const Motorcycle& other); ///< Copy constructor.
    //Motorcycle& operator=(Motorcycle other); ///< Copy assignment operator.

    friend void swap(Motorcycle& first, Motorcycle& second) noexcept; ///< Swap two motorcycles.

    ~Motorcycle() override = default; ///< Destructor.

    void display() const override; ///< Show motorcycle details.
    void performMaintenance() override; ///< Perform maintenance.
    std::unique_ptr<Vehicle> clone() const override; ///< Clone motorcycle.
    double calculateMaintenanceCost() const override; ///< Calculate maintenance cost.
    std::pair<std::string, double> optimizeResourceAllocation() const override; ///< Optimize resources.
    std::string performSafetyInspection() const override;

    double getEngineDisplacement() const; ///< Get engine displacement.
    bool getHasSidecar() const; ///< Check if it has a sidecar.

    void attachSidecar(); ///< Attach a sidecar.
};

#endif // MOTORCYCLE_H
