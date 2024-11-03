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

    fleetManager.removeVehicle(vehicles[0]);
    fleetManager.addVehicle(Vehicle(1, "Toyota", 1345, "Camry"));
    
cout << fleetManager << endl;






}




