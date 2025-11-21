#pragma once

#include <cstdint> 
#include "gpiod.hpp"

namespace Hal
{
    enum class InputLevel
    {
        Low,
        High
    };

    class DigitalInputPin
    {
    public:
        DigitalInputPin(std::uint8_t pinNumber);
        ~DigitalInputPin() = default;

        InputLevel ReadLevel();
    private:
        gpiod::chip _chip;
        gpiod::line _pin;
    };
}