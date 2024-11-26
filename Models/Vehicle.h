#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <memory>
#include <utility>

class Vehicle
{

protected:
    int vin;
    std::string model;
    int kilometers;
    std::string brand;

public:

    Vehicle(int vin, std::string  model, int kilometers, std::string  brand)
        : vin(vin), model(std::move(model)), kilometers(kilometers), brand(std::move(brand)) {}


    Vehicle(const Vehicle& other)
        : vin(other.vin), model(other.model),
          kilometers(other.kilometers), brand(other.brand) {}


    virtual ~Vehicle() = default;


    virtual void display() const = 0;
    virtual void performMaintenance() = 0;


    virtual std::unique_ptr<Vehicle> clone() const = 0;


    void showInfo() const
    {
        std::cout << "VIN: " << vin << ", Model: " << model
                  << ", Kilometers: " << kilometers << ", Brand: " << brand << std::endl;
    }


    int getVin() const
    {
        return vin;
    }

protected:

    void swapBase(Vehicle& other) noexcept
    {
        using std::swap;
        swap(vin, other.vin);
        swap(model, other.model);
        swap(kilometers, other.kilometers);
        swap(brand, other.brand);
    }

public:

    Vehicle& operator=(const Vehicle& other) = delete;

};

#endif
