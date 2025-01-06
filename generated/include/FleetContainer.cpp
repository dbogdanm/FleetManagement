#include "../generated/headers/FleetContainer.h"
#include "../Models/Driver.h"
#include "../Models/Route.h"
#include <stdexcept>

template<typename T>
void FleetContainer<T>::addItem(const T& item) {
    items.push_back(item);
}

template<typename T>
void FleetContainer<T>::displayItems() const {
    for (const auto& item : items) {
        item.display();
    }
}

template<typename T>
T FleetContainer<T>::getItem(int index) const {
    if (index >= 0 && static_cast<std::size_t>(index) < items.size()) {
        return items[index];
    }
    throw std::out_of_range("Index out of range");
}



template class FleetContainer<Driver>;
template class FleetContainer<Route>;
