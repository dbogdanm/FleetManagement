#ifndef FLEET_CONTAINER_H
#define FLEET_CONTAINER_H

#include <vector>
#include <iostream>

template<typename T>
class FleetContainer {
private:
    std::vector<T> items;
public:
    void addItem(const T& item);
    void displayItems() const;
    T getItem(int index) const;
};

#endif // FLEET_CONTAINER_H
