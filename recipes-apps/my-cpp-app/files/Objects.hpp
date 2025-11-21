#pragma once

#include "Hal/DigitalOutputPin.hpp"
#include "Hal/DigitalInputPin.hpp"

namespace Application
{
    Hal::DigitalOutputPin _testOutputPin{17, Hal::OutputLevel::Low};
    Hal::DigitalInputPin _testInputPin{27};
}