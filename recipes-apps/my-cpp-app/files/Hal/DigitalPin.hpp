#pragma once

#include <cstdint>

namespace Hal
{
    enum class PinDirection
    {
        Output,
        Input
    };

    class DigitalPin
    {
    private:
        /* data */
    public:
        DigitalPin(PinDirection pinDirection, std::uint8_t pinNumber);
        ~DigitalPin() = default;
    };
}
