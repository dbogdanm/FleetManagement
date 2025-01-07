#include "Route.h"
#include <iostream>
#include <utility>

/**
 * @brief Constructor for Route.
 * @param id Unique identifier for the route.
 * @param distance Distance of the route in kilometers.
 * @param startingPoint Starting location of the route.
 * @param endingPoint Ending location of the route.
 */
Route::Route(int id, int distance, std::string startingPoint, std::string endingPoint)
    : id(id),
      distance(distance),
      startingPoint(std::move(startingPoint)),
      endingPoint(std::move(endingPoint))
{
}

/**
 * @brief Copy constructor for Route.
 * @param other Another Route object to copy from.
 *
 * Copies all attributes from the given `Route` object.
 */
Route::Route(const Route& other)
    : id(other.id),
      distance(other.distance),
      startingPoint(other.startingPoint),
      endingPoint(other.endingPoint)
{
}

/**
 * @brief Copy assignment operator using copy-and-swap idiom.
 * @param other Another Route object to assign from.
 * @return Reference to the current object.
 */
Route& Route::operator=(Route other)
{
    swap(*this, other);
    return *this;
}

/**
 * @brief Swaps two Route objects.
 * @param first First Route object.
 * @param second Second Route object.
 *
 * Exchanges the values of all attributes between two `Route` objects.
 */
void swap(Route& first, Route& second) noexcept
{
    using std::swap;
    swap(first.id, second.id);
    swap(first.distance, second.distance);
    swap(first.startingPoint, second.startingPoint);
    swap(first.endingPoint, second.endingPoint);
}

/**
 * @brief Retrieves the route ID.
 * @return The unique identifier of the route.
 */
int Route::getId() const
{
    return id;
}

/**
 * @brief Displays route details.
 *
 * Prints the route ID, distance, starting point, and ending point.
 */
void Route::display() const
{
    std::cout << "Route ID: " << id
              << ", Distance: " << distance << " km"
              << ", From: " << startingPoint
              << " To: " << endingPoint
              << std::endl;
}
