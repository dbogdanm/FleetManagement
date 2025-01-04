#include "Driver.h"

int Driver::totalDrivers = 0;

Driver::Driver(int id, std::string name, std::string phone, int numberOfHours)
    : id(id),
      name(std::move(name)),
      phone(std::move(phone)),
      numberOfHours(numberOfHours)
{
    ++totalDrivers;
}

Driver::~Driver()
{
    --totalDrivers;
}

Driver::Driver(const Driver& other)
    : id(other.id),
      name(other.name),
      phone(other.phone),
      numberOfHours(other.numberOfHours)
{
    ++totalDrivers;
}

Driver& Driver::operator=(Driver other)
{
    swap(*this, other);
    return *this;
}

void swap(Driver& first, Driver& second) noexcept
{
    using std::swap;
    swap(first.id, second.id);
    swap(first.name, second.name);
    swap(first.phone, second.phone);
    swap(first.numberOfHours, second.numberOfHours);
}

int Driver::getId() const
{
    return id;
}

void Driver::updateNumberOfHours(int newNumberOfHours)
{
    numberOfHours = newNumberOfHours;
}

void Driver::display() const
{
    std::cout << "Driver ID: " << id
              << ", Name: " << name
              << ", Phone: " << phone
              << ", Hours: " << numberOfHours
              << std::endl;
}

int Driver::getTotalDrivers()
{
    return totalDrivers;
}
