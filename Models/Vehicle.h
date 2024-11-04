#ifndef VEHICLE_H
#define VEHICLE_H
#include <utility>
#include <vector>

using namespace std;

class Vehicle
{
    private:

    int vin;
    string model;
    int kilometers;
    string brand;

public:
    Vehicle(int vin, string name, int kilometers, string brand)
        : vin(vin),
          model(std::move(name)),
          kilometers(kilometers),
          brand(std::move(brand))
    {
    }

    Vehicle(const Vehicle &other)
    {
        vin = other.vin;
        model = other.model;
        kilometers = other.kilometers;
        brand = other.brand;
    }

    Vehicle& operator=(const Vehicle &other)
    {
        vin = other.vin;
        model = other.model;
        kilometers = other.kilometers;
        brand = other.brand;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Vehicle& vehicle)
    {
        os << "Vehicle vin: " << vehicle.vin << "\n";
        os << "Vehicle model: " << vehicle.model << "\n";
        os << "Vehicle mileage: " << vehicle.kilometers << "\n";
        os << "Vehicle brand: " << vehicle.brand << "\n";
        return os;
    }


    int updateKM(int newKilometers)
    {
        kilometers = newKilometers;
        return kilometers;
    }

    bool operator==(const Vehicle& other) const
    {
        return vin == other.vin;
    }

    int GetVin() const
    {
        return vin;
    }

    int GetKilometers() const
    {
        return kilometers;
    }


    ~Vehicle() = default;
        //string is already self managing its memory
};

#endif //VEHICLE_H
