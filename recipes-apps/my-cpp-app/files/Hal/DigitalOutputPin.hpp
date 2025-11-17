#pragma once

#include <cstdint>
#include "gpiod.hpp"

namespace Hal
{
    enum class OutputLevel
    {
        Low,
        High
    };

    class DigitalOutputPin
    {
    public:
        DigitalOutputPin(std::uint8_t pinNumber, OutputLevel startingOutputLevel);
        ~DigitalOutputPin() = default;

        void SetOutput(OutputLevel outputLevel);

    private:
        gpiod::chip _chip;
        gpiod::line _pin;
    };
}
