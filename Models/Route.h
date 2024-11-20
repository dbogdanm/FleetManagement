#ifndef ROUTE_H
#define ROUTE_H
#include <string>
#include <utility>
#include <iostream>


class Route
{
private:
    int id;
    int distance;
    std::string startingPoint;
    std::string endingPoint;

public:
    Route(int id, int distance, std::string starting_point, std::string ending_point)
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

    friend std::ostream& operator<<(std::ostream& os, const Route& route)
    {
        os << "Route id: " << route.id << "\n";
        os << "Route distance: " << route.distance << "\n";
        os << "Route starting point: " << route.startingPoint << "\n";
        os << "Route ending point: " << route.endingPoint << "\n";
        return os;
    }

    int getDistance(int startId, int endId) const
    {
        if(startId == id && endId == distance)
        {
            return distance;
        }
        else
        {
            std::cout << "Route does not match the given parameters" << std::endl;
            return -1;
        }
    }

    /*bool operator==(const Route& other) const
    {
        return id == other.id && distance == other.distance && startingPoint == other.startingPoint && endingPoint == other.endingPoint;
    }
*/
    int GetId() const
    {
        return id;
    }


    ~Route()= default;



};

#endif //ROUTE_H
