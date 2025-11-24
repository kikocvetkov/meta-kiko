#include "DigitalInputPin.hpp"
#include <iostream>

namespace Hal
{

    DigitalInputPin::DigitalInputPin(std::uint8_t pinNumber) : _chip{"gpiochip0"},
                                                               _pin{_chip.get_line(pinNumber)}
    {
        _pin.request({"pinName", gpiod::line_request::DIRECTION_INPUT});
    }

    InputLevel DigitalInputPin::ReadLevel()
    {
        if (_pin.get_value())
        {
            std::cout << "Input Level High\n";
            return InputLevel::High;
        }
        else
        {
            std::cout << "Input Level Low\n";
            return InputLevel::Low;
        }
    }
}
