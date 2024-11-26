#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
private:
    double engineDisplacement;
    bool hasSidecar;

public:

    Motorcycle(int vin, const std::string& model, int kilometers, const std::string& brand,
               double engineDisplacement, bool hasSidecar)
        : Vehicle(vin, model, kilometers, brand),
          engineDisplacement(engineDisplacement), hasSidecar(hasSidecar) {}


    Motorcycle(const Motorcycle& other)
        : Vehicle(other), engineDisplacement(other.engineDisplacement),
          hasSidecar(other.hasSidecar) {}

    //iar copy and swap
    Motorcycle& operator=(Motorcycle other)
    {
        swap(*this, other);
        return *this;
    }

    // si iar swap function cu noexcept
    friend void swap(Motorcycle& first, Motorcycle& second) noexcept
    {
        using std::swap;
        first.swapBase(second);
        swap(first.engineDisplacement, second.engineDisplacement);
        swap(first.hasSidecar, second.hasSidecar);
    }


    ~Motorcycle() override = default;

    // implementari functii virtuale:
    void display() const override
    {
        std::cout << "Motorcycle - VIN: " << vin << ", Model: " << model
                  << ", Kilometers: " << kilometers << ", Brand: " << brand
                  << ", Engine Displacement: " << engineDisplacement
                  << "cc, Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }

    void performMaintenance() override
    {
        std::cout << "Performing maintenance on Motorcycle VIN " << vin << std::endl;
        //o sa aiba o implementare mai complexa metoda asta pt milestone 3
    }


    std::unique_ptr<Vehicle> clone() const override
    {
        return std::make_unique<Motorcycle>(*this);
    }


    double getEngineDisplacement() const
    {
        return engineDisplacement;
    }

    bool getHasSidecar() const
    {
        return hasSidecar;
    }

};

#endif
