#include <iostream>
#include <array>
#include "Models/Route.h"
#include "Models/Driver.h"
#include "Models/Vehicle.h"
#include "Models/FleetManager.h"
#include "Models/Helper.h"
using namespace std;

int main()
{

vector<Driver> drivers = Helper::ReadDriverFromFile();
vector<Route> routes = Helper::ReadRouteFromFile();
vector<Vehicle> vehicles = Helper::ReadVehicleFromFile();


    FleetManager fleetManager(drivers, vehicles, routes);

    fleetManager.removeDriver(4);
    //fleetManager.removeVehicle(5);
    fleetManager.addVehicle(Vehicle(1, "Toyota", 1345, "Camry"));
    fleetManager.removeVehicle(1234);

    fleetManager.removeRoute(0);
    fleetManager.removeRoute(1);
    fleetManager.removeRoute(2);

    fleetManager.FindDriverById(3);



cout << fleetManager << endl;






}




