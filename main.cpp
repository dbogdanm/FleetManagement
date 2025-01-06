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
#include "generated/headers/VehicleFactory.h"
#include "generated/headers/ServiceObserver.h"
#include "generated/headers/FleetContainer.h"
#include "generated/headers/MaintenanceCalculator.h"

int main()
{
    try
    {
        // 🔹 1. Inițializare date din Helper
        std::vector<Driver> drivers = Helper::ReadDriverFromFile();
        std::vector<Route> routes = Helper::ReadRouteFromFile();
        std::vector<std::unique_ptr<Vehicle>> vehicles = Helper::ReadVehicleFromFile();

        for (auto& drv : drivers) {
            drv.display();
            drv.updateNumberOfHours(drv.getId() + 10);
        }
        std::cout << "Total drivers: " << Driver::getTotalDrivers() << "\n";

        for (const auto& route : routes) {
            route.display();
        }

        for (auto& veh : vehicles) {
            veh->showInfo();
            veh->display();
            veh->performMaintenance();

            if (auto bus = dynamic_cast<Bus*>(veh.get())) {
                bus->upgradeWiFi();
                bus->increaseSeatingCapacity(5);
                std::cout << "[Bus] has WiFi? " << (bus->getHasWiFi() ? "Yes" : "No") << "\n";
            }
            else if (auto truck = dynamic_cast<Truck*>(veh.get())) {
                truck->increaseLoadCapacity(2.0);
                std::cout << "[Truck] Fuel efficiency: " << truck->getFuelEfficiency() << "\n";
            }
            else if (auto moto = dynamic_cast<Motorcycle*>(veh.get())) {
                moto->attachSidecar();
                std::cout << "[Motorcycle] has sidecar? " << (moto->getHasSidecar() ? "Yes" : "No") << "\n";
            }
        }

        FleetManager fleetManager(std::move(drivers), std::move(vehicles), std::move(routes));
        fleetManager.displayFleet();

        fleetManager.addDriver(Driver(21, "Rares Popescu", "0723457819", 40));
        fleetManager.removeDriverById(21);

        fleetManager.addRoute(Route(104, 120, "Bucuresti", "Buzau"));
        fleetManager.removeRouteById(104);

        fleetManager.addVehicle(std::make_unique<Bus>(105, "Urbino", 8000, "Solaris", 45, true));
        fleetManager.removeVehicleByVin(105);

        // 🆕 2. Factory Method Pattern (VehicleFactory)
        std::cout << "\n🔹 Factory Method Pattern Tests:\n";
        std::unique_ptr<Vehicle> factoryBus = VehicleFactory::createVehicle("Bus");
        std::unique_ptr<Vehicle> factoryTruck = VehicleFactory::createVehicle("Truck");
        std::unique_ptr<Vehicle> factoryMotorcycle = VehicleFactory::createVehicle("Motorcycle");

        factoryBus->display();
        factoryTruck->display();
        factoryMotorcycle->display();

        // 🆕 3. Observer Pattern (ServiceObserver)
        std::cout << "\n🔹 Observer Pattern Tests:\n";
        VehicleServiceNotifier notifier;
        ServiceObserver observer1, observer2;

        notifier.addObserver(&observer1);
        notifier.addObserver(&observer2);

        notifier.notifyObservers("Service started for a vehicle!");
        notifier.notifyObservers("Service completed for a vehicle!");

        // 🆕 4. FleetContainer Template Class Tests
        std::cout << "\n🔹 FleetContainer Template Tests:\n";
        FleetContainer<Driver> driverContainer;
        driverContainer.addItem(Driver(30, "Elena Ionescu", "0734567890", 60));
        driverContainer.addItem(Driver(31, "Mihai Vasile", "0745678901", 45));
        driverContainer.displayItems();

        FleetContainer<Route> routeContainer;
        routeContainer.addItem(Route(301, 400, "Brasov", "Sibiu"));
        routeContainer.addItem(Route(302, 250, "Iasi", "Bacau"));
        routeContainer.displayItems();

        // 🆕 5. Template Function for Maintenance Cost
        std::cout << "\n🔹 Template Function Tests:\n";
        Truck testTruck(501, "HeavyTruck", 15000, "MAN", 20.5, 10.5);
        Bus testBus(502, "CityBus", 5000, "Mercedes", 60, true);
        Motorcycle testMotorcycle(503, "SpeedMoto", 2000, "Yamaha", 750.0, false);

        calculateAndDisplayCost(testTruck);
        calculateAndDisplayCost(testBus);
        calculateAndDisplayCost(testMotorcycle);

    }
    catch (const FleetException& ex) {
        std::cerr << "FleetException caught: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Standard exception caught: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown exception caught." << std::endl;
    }

    return 0;
}
