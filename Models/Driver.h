#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>

/**
 * @class Driver
 * @brief Represents a driver in the fleet.
 */
class Driver
{
private:
    int id; ///< Unique driver ID.
    std::string name; ///< Driver's name.
    std::string phone; ///< Driver's phone number.
    int numberOfHours; ///< Hours worked by the driver.
    static int totalDrivers; ///< Total number of drivers.

public:
    Driver(int id, std::string name, std::string phone, int numberOfHours); ///< Constructor.
    ~Driver(); ///< Destructor.
    Driver(const Driver& other); ///< Copy constructor.
    Driver& operator=(Driver other); ///< Copy assignment operator.

    friend void swap(Driver& first, Driver& second) noexcept; ///< Swap two drivers.

    [[nodiscard]] int getId() const; ///< Get driver ID.
    void updateNumberOfHours(int newNumberOfHours); ///< Update hours worked.
    void display() const; ///< Display driver details.
    static int getTotalDrivers(); ///< Get total driver count.
};

#endif // DRIVER_H
