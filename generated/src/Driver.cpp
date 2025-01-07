#include "Driver.h"


/**
 * @brief Initializes a Driver object.
 * @param id Unique identifier for the driver.
 * @param name Name of the driver.
 * @param phone Contact number of the driver.
 * @param numberOfHours Number of hours worked by the driver.
 *
 * Increments the static counter for total drivers upon creation.
 */
int Driver::totalDrivers = 0;
Driver::Driver(int id, std::string name, std::string phone, int numberOfHours)
    : id(id),
      name(std::move(name)),
      phone(std::move(phone)),
      numberOfHours(numberOfHours)
{
    ++totalDrivers;
}

/**
 * @brief Destructor for Driver.
 *
 * Decrements the static counter for total drivers upon destruction.
 */
Driver::~Driver()
{
    --totalDrivers;
}

/**
 * @brief Copy constructor for Driver.
 * @param other Another Driver object to copy from.
 *
 * Copies all attributes and increments the total drivers counter.
 */
Driver::Driver(const Driver& other)
    : id(other.id),
      name(other.name),
      phone(other.phone),
      numberOfHours(other.numberOfHours)
{
    ++totalDrivers;
}

/**
 * @brief Copy assignment operator using copy-and-swap idiom.
 * @param other Another Driver object to assign from.
 * @return Reference to the current object.
 */
Driver& Driver::operator=(Driver other)
{
    swap(*this, other);
    return *this;
}

/**
 * @brief Swaps two Driver objects.
 * @param first First Driver object.
 * @param second Second Driver object.
 *
 * Safely exchanges all member attributes between two Driver objects.
 */
void swap(Driver& first, Driver& second) noexcept
{
    using std::swap;
    swap(first.id, second.id);
    swap(first.name, second.name);
    swap(first.phone, second.phone);
    swap(first.numberOfHours, second.numberOfHours);
}

/**
 * @brief Retrieves the driver's unique ID.
 * @return The ID of the driver.
 */
int Driver::getId() const
{
    return id;
}

/**
 * @brief Updates the number of hours worked by the driver.
 * @param newNumberOfHours New number of hours to set.
 */
void Driver::updateNumberOfHours(int newNumberOfHours)
{
    numberOfHours = newNumberOfHours;
}

/**
 * @brief Displays driver details.
 *
 * Prints the driver's ID, name, phone number, and total hours worked.
 */
void Driver::display() const
{
    std::cout << "Driver ID: " << id
              << ", Name: " << name
              << ", Phone: " << phone
              << ", Hours: " << numberOfHours
              << std::endl;
}

/**
 * @brief Retrieves the total number of active drivers.
 * @return Total number of drivers.
 *
 * This is a static method that returns the value of the static `totalDrivers` counter.
 */
int Driver::getTotalDrivers()
{
    return totalDrivers;
}
