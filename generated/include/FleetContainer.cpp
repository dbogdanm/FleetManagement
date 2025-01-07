#include "../generated/headers/FleetContainer.h"
#include "../Models/Driver.h"
#include "../Models/Route.h"
#include <stdexcept>

/**
 * @brief Adds an item to the container.
 * @tparam T Type of the object to add.
 * @param item The object to be added.
 *
 * Pushes the given object to the end of the internal container.
 */
template<typename T>
void FleetContainer<T>::addItem(const T& item)
{
    items.push_back(item);
}

/**
 * @brief Displays all items in the container.
 * @tparam T Type of the objects in the container.
 *
 * Calls the `display()` method for each object in the container.
 */
template<typename T>
void FleetContainer<T>::displayItems() const
{
    for (const auto& item : items)
    {
        item.display();
    }
}

/**
 * @brief Retrieves an item by index.
 * @tparam T Type of the objects in the container.
 * @param index Index of the object to retrieve.
 * @return A copy of the object at the specified index.
 *
 * @throws std::out_of_range If the index is invalid.
 */
template<typename T>
T FleetContainer<T>::getItem(int index) const
{
    if (index >= 0 && static_cast<std::size_t>(index) < items.size())
    {
        return items[index];
    }
    throw std::out_of_range("Index out of range");
}


template class FleetContainer<Driver>;
template class FleetContainer<Route>;
