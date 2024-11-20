#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>
#include "Driver.h"

namespace fs = std::filesystem;

class Helper
{
public:
    static std::vector<Driver> ReadDriverFromFile()
    {
        std::ifstream file(DriverFilePath);
        if (!file)
        {
            std::cout << DriverFileNotFound << std::endl;
            return {};
        }

        std::vector<Driver> drivers;
        int numberOfDrivers;
        file >> numberOfDrivers;

        for (int i = 0; i < numberOfDrivers; i++)
        {
            int id, numberOfHours;
            std::string name, phone;
            if (file >> id >> name >> phone >> numberOfHours)
            {
                drivers.emplace_back(id, name, phone, numberOfHours);
            }
            else
            {
                std::cout << DriverReadError << i + 1 << std::endl;
            }
        }

        file.close();
        return drivers;
    }

    static std::vector<Route> ReadRouteFromFile()
    {
        std::ifstream file(RouteFilePath);
        if (!file)
        {
            std::cout << RouteFileNotFound << std::endl;
            return {};
        }

        std::vector<Route> routes;
        int numberOfRoutes;
        file >> numberOfRoutes;

        for (int i = 0; i < numberOfRoutes; i++)
        {
            int id, distance;
            std::string startingPoint, endingPoint;
            if (file >> id >> distance >> startingPoint >> endingPoint)
            {
                routes.emplace_back(id, distance, startingPoint, endingPoint);
            }
            else
            {
                std::cout << RouteReadError << i + 1 << std::endl;
            }
        }

        file.close();
        return routes;
    }

    static std::vector<Vehicle> ReadVehicleFromFile()
    {
        std::ifstream file(VehicleFilePath);
        if (!file)
        {
            std::cout << VehicleFileNotFound << std::endl;
            return {};
        }

        std::vector<Vehicle> vehicles;
        int numberOfVehicles;
        file >> numberOfVehicles;

        for (int i = 0; i < numberOfVehicles; i++)
        {
            int id, kilometers;
            std::string brand, model;
            if (file >> id >> model >> kilometers >> brand)
            {
                vehicles.emplace_back(id, model, kilometers, brand);
            }
            else
            {
                std::cout << VehicleReadError << i + 1 << std::endl;
            }
        }

        file.close();
        return vehicles;
    }

private:
    static const fs::path DriverFilePath;
    static const std::string DriverFileNotFound;
    static const std::string DriverReadError;
    static const std::string RouteReadError;
    static const std::string RouteFileNotFound;
    static const fs::path RouteFilePath;
    static const fs::path VehicleFilePath;
    static const std::string VehicleFileNotFound;
    static const std::string VehicleReadError;
};

const fs::path Helper::DriverFilePath = R"(C:\Users\gicap\OneDrive\Desktop\OOP\Project\Driver.txt)";
const fs::path Helper::RouteFilePath = R"(C:\Users\gicap\OneDrive\Desktop\OOP\Project\Routes.txt)";
const fs::path Helper::VehicleFilePath = R"(C:\Users\gicap\OneDrive\Desktop\OOP\Project\Vehicle.txt)";

const std::string Helper::DriverFileNotFound = "Driver.txt not found";
const std::string Helper::RouteFileNotFound = "Routes.txt not found";
const std::string Helper::VehicleFileNotFound = "Vehicle.txt not found";

const std::string Helper::DriverReadError = "Error while reading from Driver.txt";
const std::string Helper::RouteReadError = "Error while reading from Routes.txt";
const std::string Helper::VehicleReadError = "Error while reading from Vehicle.txt";

#endif // HELPER_H
