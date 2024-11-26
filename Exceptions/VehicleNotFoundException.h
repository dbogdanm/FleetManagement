#ifndef VEHICLENOTFOUNDEXCEPTION_H
#define VEHICLENOTFOUNDEXCEPTION_H

#include "FleetException.h"

class VehicleNotFoundException : public FleetException
{
public:

    explicit VehicleNotFoundException(int vin)
        : FleetException("Vehicle with VIN " + std::to_string(vin) + " not found.") {}
};

#endif
