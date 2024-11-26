#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <memory>
#include "Driver.h"
#include "Route.h"
#include "Bus.h"
#include "Truck.h"
#include "Motorcycle.h"

class Helper {
public:
    static std::vector<Driver> ReadDriverFromFile()
    {
        return
        { //nu stiu de ce nu se indenteaza acolada aia bine
            Driver(1, "Hunter Biden", "0713456791", 347),
            Driver(2, "Bradley Carter", "0787654321", 118)
        };
    }

    static std::vector<Route> ReadRouteFromFile()
    {
        // AM RENUNTAT DIN A MAI FOLOSI FISIERE
        return
        {
            Route(1, 148, "Ramnicu-Sarat", "Bucharest"),
            Route(2, 305, "Suceava", "Cluj")
        };
    }

    static std::vector<std::unique_ptr<Vehicle>> ReadVehicleFromFile()
    {
        std::vector<std::unique_ptr<Vehicle>> vehicles;
        vehicles.emplace_back(std::make_unique<Bus>(101, "Citaro", 345000, "Mercedes-Benz", 73, false));
        vehicles.emplace_back(std::make_unique<Truck>(102, "S-Series", 320000, "Scania", 21, 38));
        vehicles.emplace_back(std::make_unique<Motorcycle>(103, "Primavera", 1000, "Vespa", 125.0, false));
        return vehicles;
    }
};

#endif
