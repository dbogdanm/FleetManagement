#ifndef FLEETEXCEPTION_H
#define FLEETEXCEPTION_H

#include <exception>
#include <string>
#include <utility>

class FleetException : public std::exception
{
protected:
    std::string message;
public:

    explicit FleetException(std::string  msg) : message(std::move(msg)) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

#endif
