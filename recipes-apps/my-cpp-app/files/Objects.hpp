#pragma once

#include "Hal/DigitalOutputPin.hpp"
#include "Hal/DigitalInputPin.hpp"
#include "Tasks/BleTask.hpp"
#include "Drivers/Wireless/WiFi/Wifi.hpp"

namespace Objects
{
    Hal::DigitalOutputPin testOutputPin{17, Hal::OutputLevel::Low};
    Hal::DigitalInputPin testInputPin{27};

    Drivers::Wireless::Wifi::Wifi wifi;

    Tasks::BleTask bleTask;
}
