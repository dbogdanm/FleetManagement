#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <iostream>
#include <utility>

/**
 * @class Route
 * @brief Represents a transportation route.
 */
class Route
{
private:
    int id; ///< Unique route identifier.
    int distance; ///< Route distance in kilometers.
    std::string startingPoint; ///< Starting point of the route.
    std::string endingPoint; ///< Ending point of the route.

public:
    Route(int id, int distance, std::string startingPoint, std::string endingPoint); ///< Constructor.
    Route(const Route& other); ///< Copy constructor.
    Route& operator=(Route other); ///< Copy assignment operator.

    friend void swap(Route& first, Route& second) noexcept; ///< Swap two routes.

    [[nodiscard]] int getId() const; ///< Get route ID.
    void display() const; ///< Display route details.
};

#endif // ROUTE_H
