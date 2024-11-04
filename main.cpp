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

    // Driver driver(20, "Rares", "0723457819", 40);
    // Route route(104, 130, "Buzau", "Bucuresti");

    fleetManager.addDriver(Driver(21, "Rares", "0723457819", 40));
    fleetManager.removeDriverById(4);


    fleetManager.addVehicle(Vehicle(1, "Toyota", 1345, "Camry"));
    fleetManager.removeVehicleByVin(1234);

    fleetManager.addRoute(Route(104, 120, "Bucuresti", "Buzau"));
    fleetManager.removeRouteById(104);

    fleetManager.FindDriverById(3);

    Vehicle Test(232, "X6", 193232, "BMW");
    Test.updateKM(130000);
    Test.GetVin();
    cout<<Test.GetKilometers() << endl;
    Vehicle Test2 = Test;
    cout<<Test2.GetKilometers() << endl;

    Driver Test1(20, "Joanna", "0777777777", 0);
    Test1.updateNumberOfHours(230);
    cout << "NO of hours " << Test1.GetNumberOfHours() << endl;

    fleetManager.addDriver(Test1);



    cout << fleetManager << endl;







}




