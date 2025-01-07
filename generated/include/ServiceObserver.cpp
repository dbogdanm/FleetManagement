#include "../headers/ServiceObserver.h"
#include <iostream>

/**
 * @brief Adds an observer to the notifier.
 *
 * @param observer Pointer to the observer to be added.
 *
 * Adds the given observer to the list of observers
 * that will receive notifications.
 */
void VehicleServiceNotifier::addObserver(Observer* observer)
{
    observers.push_back(observer);
}

/**
 * @brief Notifies all registered observers.
 *
 * @param message The message to be sent to observers.
 *
 * Iterates through all observers and calls their `update` method
 * with the given message.
 */
void VehicleServiceNotifier::notifyObservers(const std::string& message)
{
    for (auto observer : observers)
    {
        observer->update(message);
    }
}

/**
 * @brief Handles an update from the notifier.
 *
 * @param message The notification message.
 *
 * Prints the received notification message to the console.
 */
void ServiceObserver::update(const std::string& message)
{
    std::cout << "[Notification] " << message << std::endl;
}
