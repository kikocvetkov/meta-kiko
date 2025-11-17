#pragma once

#include "Hal/DigitalOutputPin.hpp"

namespace Application
{
    Hal::DigitalOutputPin _testPin{17, Hal::OutputLevel::Low};
}