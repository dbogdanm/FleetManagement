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

int main()
{
    try
    {
        // 1) Luăm datele inițiale "hardcodate" din Helper
        std::vector<Driver> drivers = Helper::ReadDriverFromFile();
        std::vector<Route> routes   = Helper::ReadRouteFromFile();
        std::vector<std::unique_ptr<Vehicle>> vehicles = Helper::ReadVehicleFromFile();

        // 2) Apelăm metode "unused" pe aceste liste LOCALE ca să nu apară warn
        //    Apelăm TOT: display, updateNumberOfHours, getTotalDrivers, etc.
        for (auto &drv : drivers)
        {
            drv.display();
            drv.updateNumberOfHours(drv.getId() + 10);
        }
        std::cout << "Total drivers: " << Driver::getTotalDrivers() << "\n";

        for (const auto &r : routes)
        {
            r.display();
        }

        for (auto &veh : vehicles)
        {
            // Metodele din Vehicle
            veh->showInfo();
            veh->display();
            veh->performMaintenance();

            // Dinamic cast la tipuri derivate: Bus, Truck, Motorcycle
            if (auto bus = dynamic_cast<Bus*>(veh.get()))
            {
                // Apelăm noile metode => upgradeWiFi, increaseSeatingCapacity
                bus->upgradeWiFi();
                bus->increaseSeatingCapacity(5);
                // Apelăm și getHasWiFi() etc.
                std::cout << "[Bus] has WiFi? " << (bus->getHasWiFi() ? "Yes" : "No") << "\n";
            }
            else if (auto truck = dynamic_cast<Truck*>(veh.get()))
            {
                truck->increaseLoadCapacity(2.0);
                std::cout << "[Truck] Fuel efficiency: " << truck->getFuelEfficiency() << "\n";
            }
            else if (auto moto = dynamic_cast<Motorcycle*>(veh.get()))
            {
                moto->attachSidecar();
                std::cout << "[Motorcycle] has sidecar? "
                          << (moto->getHasSidecar() ? "Yes" : "No") << "\n";
            }
        }

        // 3) Creăm FleetManager cu aceste liste (migrate prin std::move)
        FleetManager fleetManager(std::move(drivers), std::move(vehicles), std::move(routes));

        // 4) Apelăm metode din FleetManager (incl. add, remove, display)
        fleetManager.displayFleet();

        fleetManager.addDriver(Driver(21, "Rares Popescu", "0723457819", 40));
        fleetManager.removeDriverById(21);

        fleetManager.addRoute(Route(104, 120, "Bucuresti", "Buzau"));
        fleetManager.removeRouteById(104);

        // Adăugăm un Bus și îl scoatem la final (ca să-l folosim puțin)
        fleetManager.addVehicle(std::make_unique<Bus>(105, "Urbino", 8000, "Solaris", 45, true));
        fleetManager.removeVehicleByVin(105);
    }
    catch (const FleetException &ex)
    {
        std::cerr << "FleetException caught: " << ex.what() << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Standard exception caught: " << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown exception caught." << std::endl;
    }

    return 0;
}
