#include "Route.h"

Route::Route(int id, int distance, std::string startingPoint, std::string endingPoint)
    : id(id),
      distance(distance),
      startingPoint(std::move(startingPoint)),
      endingPoint(std::move(endingPoint))
{
}

Route::Route(const Route& other)
    : id(other.id),
      distance(other.distance),
      startingPoint(other.startingPoint),
      endingPoint(other.endingPoint)
{
}

Route& Route::operator=(Route other)
{
    swap(*this, other);
    return *this;
}

void swap(Route& first, Route& second) noexcept
{
    using std::swap;
    swap(first.id, second.id);
    swap(first.distance, second.distance);
    swap(first.startingPoint, second.startingPoint);
    swap(first.endingPoint, second.endingPoint);
}

int Route::getId() const
{
    return id;
}

void Route::display() const
{
    std::cout << "Route ID: " << id
              << ", Distance: " << distance << " km"
              << ", From: " << startingPoint
              << " To: " << endingPoint
              << std::endl;
}
