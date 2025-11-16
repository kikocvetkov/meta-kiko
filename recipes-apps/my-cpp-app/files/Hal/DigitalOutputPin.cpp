#include "DigitalOutputPin.hpp"

namespace Hal
{
    DigitalOutputPin::DigitalOutputPin(std::uint8_t pinNumber, OutputLevel startingOutputLevel) :
    _chip{"gpiochip0"},
    _pin{_chip.get_line(pinNumber)}
    {
        _pin.request({"pinName", gpiod::line_request::DIRECTION_OUTPUT, 0});
    }

    void DigitalOutputPin::SetOutput(OutputLevel outputLevel)
    {
        if(outputLevel == OutputLevel::Low)
        {
            _pin.set_value(0);
        }
        else
        {
            _pin.set_value(1);
        }
    }
}
