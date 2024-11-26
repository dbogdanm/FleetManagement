#ifndef ROUTENOTFOUNDEXCEPTION_H
#define ROUTENOTFOUNDEXCEPTION_H

#include "FleetException.h"

class RouteNotFoundException : public FleetException
{
public:

    explicit RouteNotFoundException(int routeId)
        : FleetException("Route with ID " + std::to_string(routeId) + " not found.") {}
};

#endif
