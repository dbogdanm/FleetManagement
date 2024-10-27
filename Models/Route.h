#ifndef ROUTE_H
#define ROUTE_H
#include <string>
#include <utility>
#include <iostream>
using namespace std;

class Route
{
private:
    int id;
    int distance;
    string startingPoint;
    string endingPoint;

public:
    Route(int id, int distance, string starting_point, string ending_point)
        : id(id),
          distance(distance),
          startingPoint(std::move(starting_point)),
          endingPoint(std::move(ending_point))
    {
    }

    Route(const Route &other)
    {
        id = other.id;
        distance = other.distance;
        startingPoint = other.startingPoint;
        endingPoint = other.endingPoint;
    }

    Route& operator=(const Route &other)
    {
        id = other.id;
        distance = other.distance;
        startingPoint = other.startingPoint;
        endingPoint = other.endingPoint;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Route& route)
    {
        os << "Driver id: " << route.id << "\n";
        os << "Driver name: " << route.distance << "\n";
        os << "Driver phone: " << route.startingPoint << "\n";
        os << "Driver number of hours: " << route.endingPoint << "\n";
        return os;
    }

    ~Route()
    = default;

};

#endif //ROUTE_H
