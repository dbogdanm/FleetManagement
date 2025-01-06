#include "../headers/ServiceObserver.h"
#include <iostream>

void VehicleServiceNotifier::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void VehicleServiceNotifier::notifyObservers(const std::string& message) {
    for (auto observer : observers) {
        observer->update(message);
    }
}

void ServiceObserver::update(const std::string& message) {
    std::cout << "[Notification] " << message << std::endl;
}
