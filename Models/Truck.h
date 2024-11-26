#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{

private:
    double loadCapacity;
    double fuelEfficiency;

public:

    Truck(const int vin, const std::string& model, const int kilometers, const std::string& brand,
          const double loadCapacity, const double fuelEfficiency)
        : Vehicle(vin, model, kilometers, brand),
          loadCapacity(loadCapacity), fuelEfficiency(fuelEfficiency) {}


    Truck(const Truck& other)
        : Vehicle(other), loadCapacity(other.loadCapacity),
          fuelEfficiency(other.fuelEfficiency) {}


    Truck& operator=(Truck other)
    {
        swap(*this, other);
        return *this;
    }


    friend void swap(Truck& first, Truck& second) noexcept
    {
        using std::swap;
        first.swapBase(second);
        swap(first.loadCapacity, second.loadCapacity);
        swap(first.fuelEfficiency, second.fuelEfficiency);
    }


    ~Truck() override = default;

    //implementare pt functiile virtuale din vehicle.h
    void display() const override
    {
        std::cout << "Truck - VIN: " << vin << ", Model: " << model
                  << ", Kilometers: " << kilometers << ", Brand: " << brand
                  << ", Load Capacity: " << loadCapacity
                  << " tons, Fuel Efficiency: " << fuelEfficiency << " L/100km" << std::endl;
    }

    void performMaintenance() override
    {
        std::cout << "Performing maintenance on Truck VIN " << vin << std::endl;
        //implementare mai complexa pt milestone 3
    }


    std::unique_ptr<Vehicle> clone() const override
    {
        return std::make_unique<Truck>(*this);
    }


    double getLoadCapacity() const
    {
        return loadCapacity;
    }

    double getFuelEfficiency() const
    {
        return fuelEfficiency;
    }

};

#endif
