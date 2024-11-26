// main.cpp
#include <iostream>
#include <memory>
#include "Models/Bus.h"
#include "Models/Truck.h"
#include "Models/Motorcycle.h"
#include "Models/Route.h"
#include "Models/Driver.h"
#include "Models/FleetManager.h"
#include "Models/Helper.h"
#include "Exceptions/DriverNotFoundException.h"
#include "Exceptions/RouteNotFoundException.h"
#include "Exceptions/VehicleNotFoundException.h"

int main() {
    try
        {

        std::vector<Driver> drivers = Helper::ReadDriverFromFile();
        std::vector<Route> routes = Helper::ReadRouteFromFile();
        std::vector<std::unique_ptr<Vehicle>> vehicles = Helper::ReadVehicleFromFile();


        FleetManager fleetManager(std::move(drivers), std::move(vehicles), std::move(routes));


        fleetManager.addDriver(Driver(21, "Rares Popescu", "0723457819", 40));


        //fleetManager.removeDriverById(4); //id 4 nu exista, AICI TESTEZ EXCEPTIA!!!!!!!


        fleetManager.addRoute(Route(104, 120, "Bucuresti", "Buzau"));


        fleetManager.removeRouteById(104);


        fleetManager.addVehicle(std::make_unique<Bus>(105, "Urbino", 8000, "Solaris", 45, true));


        fleetManager.displayFleet();

    }

    catch (const FleetException& ex)
    {
        std::cerr << "FleetException caught: " << ex.what() << std::endl;
    }

    catch (const std::exception& ex)
    {
        std::cerr << "Standard exception caught: " << ex.what() << std::endl;
    }

    catch (...)
    {
        std::cerr << "Unknown exception caught." << std::endl;
    }

    return 0;
}
