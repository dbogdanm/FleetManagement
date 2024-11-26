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

    Driver(int id, std::string  name, std::string  phone, int numberOfHours)
        : id(id), name(std::move(name)), phone(std::move(phone)), numberOfHours(numberOfHours)
    {
        ++totalDrivers;
    }


    ~Driver()
    {
        --totalDrivers;
    }


    Driver(const Driver& other)
        : id(other.id), name(other.name),
          phone(other.phone), numberOfHours(other.numberOfHours)
    {
        ++totalDrivers;
    }


    Driver& operator=(Driver other)
    { // prin valoare
        swap(*this, other);
        return *this;
    }


    friend void swap(Driver& first, Driver& second) noexcept
    {
        using std::swap;
        swap(first.id, second.id);
        swap(first.name, second.name);
        swap(first.phone, second.phone);
        swap(first.numberOfHours, second.numberOfHours);
    }

    //am nevoie aici de getter pentru ca folosesc functia asta pentru interfata
    //si decat sa scriu acolo 15 linii de cod mai bine 4 aici (stiu ca mi-ati spus sa sterg getters si setters)
    int getId() const
    {
        return id;
    }


    void updateNumberOfHours(int newNumberOfHours)
    {
        numberOfHours = newNumberOfHours;
    }


    void display() const
    {
        std::cout << "Driver ID: " << id << ", Name: " << name
                  << ", Phone: " << phone << ", Hours: " << numberOfHours << std::endl;
    }


    static int getTotalDrivers()
    {
        return totalDrivers;
    }
};


int Driver::totalDrivers = 0;

#endif
