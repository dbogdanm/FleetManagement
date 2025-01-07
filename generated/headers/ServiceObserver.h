#ifndef SERVICE_OBSERVER_H
#define SERVICE_OBSERVER_H

#include <vector>
#include <string>

/**
 * @brief Abstract base class for observers.
 *
 * Defines an interface for receiving updates from a subject.
 */
class Observer
{
public:
    /**
     * @brief Handles updates with a message.
     * @param message The update message.
     */
    virtual void update(const std::string& message) = 0;

    /// @brief Virtual destructor for proper cleanup.
    virtual ~Observer() = default;
};

/**
 * @brief Manages and notifies observers about updates.
 *
 * Allows adding observers and sending notifications.
 */
class VehicleServiceNotifier
{
private:
    std::vector<Observer*> observers; ///< List of registered observers.

public:
    /**
     * @brief Adds an observer to the list.
     * @param observer Pointer to the observer to add.
     */
    void addObserver(Observer* observer);

    /**
     * @brief Notifies all observers with a message.
     * @param message The message to notify observers with.
     */
    void notifyObservers(const std::string& message);
};

/**
 * @brief Concrete implementation of an observer.
 *
 * Receives and handles notifications from `VehicleServiceNotifier`.
 */
class ServiceObserver : public Observer
{
public:
    /**
     * @brief Processes the received update message.
     * @param message The message to process.
     */
    void update(const std::string& message) override;
};

#endif // SERVICE_OBSERVER_H
