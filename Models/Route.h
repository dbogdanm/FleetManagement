// Models/Route.h
#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <iostream>
#include <utility>

class Route
{

private:
    int id;
    int distance;
    std::string startingPoint;
    std::string endingPoint;

public:

    Route(int id, int distance, std::string  startingPoint, std::string  endingPoint)
        : id(id), distance(distance), startingPoint(std::move(startingPoint)), endingPoint(std::move(endingPoint)) {}


    Route(const Route& other)
        : id(other.id), distance(other.distance),
          startingPoint(other.startingPoint), endingPoint(other.endingPoint) {}


    Route& operator=(Route other)
    {
        swap(*this, other);
        return *this;
    }


    friend void swap(Route& first, Route& second) noexcept
    {
        using std::swap;
        swap(first.id, second.id);
        swap(first.distance, second.distance);
        swap(first.startingPoint, second.startingPoint);
        swap(first.endingPoint, second.endingPoint);
    }

    // din nou, am nevoie pt interfata de getters
    int getId() const
    {
        return id;
    }


    void display() const
    {
        std::cout << "Route ID: " << id << ", Distance: " << distance
                  << " km, From: " << startingPoint << " To: " << endingPoint << std::endl;
    }

};

#endif
