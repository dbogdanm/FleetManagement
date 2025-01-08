#ifndef FLEET_CONTAINER_H
#define FLEET_CONTAINER_H

#include <vector>

/**
 * @class FleetContainer
 * @brief A template class for managing a generic container of objects.
 *
 * The `FleetContainer` class provides functionalities to add, display,
 * and retrieve objects stored in an internal vector. It is designed
 * for managing entities such as drivers, vehicles, or routes in a fleet management system.
 *
 * @tparam T The type of objects stored in the container.
 */
template<typename T>
class FleetContainer
{
private:
    /**
     * @brief Internal vector for storing objects.
     *
     * This vector holds all the objects added to the container.
     */
    std::vector<T> items;

public:
    /**
     * @brief Adds an object to the container.
     *
     * @param item A constant reference to the object to be added.
     *
     * @details The object is added to the end of the internal vector.
     *
     * @note The object is copied into the vector.
     */
    void addItem(const T& item);

    /**
     * @brief Displays all objects in the container.
     *
     * @details Iterates through the internal vector and calls the `display()` method
     * on each object, assuming the type `T` has such a method implemented.
     */
    void displayItems() const;

    /**
     * @brief Retrieves an object from the container at a specific index.
     *
     * @param index The index of the desired object.
     * @return A copy of the object at the specified index.
     *
     * @throws std::out_of_range If the index is out of bounds.
     *
     * @details The method returns a copy of the object at the specified index.
     */
    T getItem(int index) const;
};

#endif // FLEET_CONTAINER_H
