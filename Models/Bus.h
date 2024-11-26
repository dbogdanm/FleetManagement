#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus : public Vehicle
{
private:
    int seatingCapacity;
    bool hasWiFi;

public:

    Bus(int vin, const std::string& model, int kilometers, const std::string& brand,
        int seatingCapacity, bool hasWiFi)
        : Vehicle(vin, model, kilometers, brand),
          seatingCapacity(seatingCapacity), hasWiFi(hasWiFi) {}


    Bus(const Bus& other)
        : Vehicle(other), seatingCapacity(other.seatingCapacity), hasWiFi(other.hasWiFi) {}


    Bus& operator=(Bus other)
    {
        swap(*this, other);
        return *this;
    }


    friend void swap(Bus& first, Bus& second) noexcept
    {
        using std::swap;
        first.swapBase(second); // schimba membrii de baza
        swap(first.seatingCapacity, second.seatingCapacity);
        swap(first.hasWiFi, second.hasWiFi);
    }


    ~Bus() override = default;


    void display() const override
    {
        std::cout << "Bus - VIN: " << vin << ", Model: " << model
                  << ", Kilometers: " << kilometers << ", Brand: " << brand
                  << ", Seating Capacity: " << seatingCapacity
                  << ", WiFi: " << (hasWiFi ? "Yes" : "No") << std::endl;
    }

    void performMaintenance() override
    {
        std::cout << "Performing maintenance on Bus VIN " << vin << std::endl;

    }


    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override
    {
        return std::make_unique<Bus>(*this);
    }

    //am nevoie aici de getter pentru ca folosesc functia asta pentru interfata
    //si decat sa scriu acolo 15 linii de cod mai bine 4 aici (stiu ca mi-ati spus sa sterg getters si setters)
    int getSeatingCapacity() const
    {
        return seatingCapacity;
    }

    bool getHasWiFi() const
    {
        return hasWiFi;
    }
};

#endif
