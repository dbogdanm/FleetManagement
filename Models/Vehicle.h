#ifndef VEHICLE_H
#define VEHICLE_H
#include <utility>
using namespace std;

class Vehicle
{
    private:

    int vin;
    string name;
    int kilometers;
    string brand;

public:
    Vehicle(int vin, string name, int kilometers, string brand)
        : vin(vin),
          name(std::move(name)),
          kilometers(kilometers),
          brand(std::move(brand))
    {
    }

    Vehicle(const Vehicle &other)
    {
        vin = other.vin;
        name = other.name;
        kilometers = other.kilometers;
        brand = other.brand;
    }

    Vehicle& operator=(const Vehicle &other)
    {
        vin = other.vin;
        name = other.name;
        kilometers = other.kilometers;
        brand = other.brand;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Vehicle& vehicle)
    {
        os << "Driver id: " << vehicle.vin << "\n";
        os << "Driver name: " << vehicle.name << "\n";
        os << "Driver phone: " << vehicle.kilometers << "\n";
        os << "Driver number of hours: " << vehicle.brand << "\n";
        return os;
    }

    ~Vehicle() = default;
        //string is already self managing its memory
};

#endif //VEHICLE_H
