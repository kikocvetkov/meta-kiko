#pragma once

#include "Hal/DigitalOutputPin.hpp"
#include "Hal/DigitalInputPin.hpp"
#include "Tasks/BleTask.hpp"

namespace Objects
{
    Hal::DigitalOutputPin _testOutputPin{17, Hal::OutputLevel::Low};
    Hal::DigitalInputPin _testInputPin{27};

    Tasks::BleTask _bleTask;
}
