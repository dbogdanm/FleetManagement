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
    Route(int id, int distance, std::string startingPoint, std::string endingPoint);
    Route(const Route& other);
    Route& operator=(Route other);

    friend void swap(Route& first, Route& second) noexcept;

    [[nodiscard]] int getId() const;
    void display() const;
};

#endif // ROUTE_H
