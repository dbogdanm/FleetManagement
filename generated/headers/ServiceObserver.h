#ifndef SERVICE_OBSERVER_H
#define SERVICE_OBSERVER_H

#include <vector>
#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
};

class VehicleServiceNotifier {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer);
    void notifyObservers(const std::string& message);
};

class ServiceObserver : public Observer {
public:
    void update(const std::string& message) override;
};

#endif // SERVICE_OBSERVER_H
