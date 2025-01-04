#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>
#include <utility>

class Driver
{
private:
    int id;
    std::string name;
    std::string phone;
    int numberOfHours;
    static int totalDrivers;

public:
    Driver(int id, std::string name, std::string phone, int numberOfHours);
    ~Driver();
    Driver(const Driver& other);
    Driver& operator=(Driver other);

    friend void swap(Driver& first, Driver& second) noexcept;

    [[nodiscard]] int getId() const;
    void updateNumberOfHours(int newNumberOfHours);
    void display() const;
    static int getTotalDrivers();
};

#endif // DRIVER_H
