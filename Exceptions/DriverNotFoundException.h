#ifndef DRIVERNOTFOUNDEXCEPTION_H
#define DRIVERNOTFOUNDEXCEPTION_H

#include "FleetException.h"

class DriverNotFoundException : public FleetException
{
public:
    explicit DriverNotFoundException(int driverId)
        : FleetException("Driver with ID " + std::to_string(driverId) + " not found.") {}
};

#endif
