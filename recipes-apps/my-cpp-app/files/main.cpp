#include <iostream>
#include <chrono>
#include <thread>
#include "Objects.hpp"

using namespace Application;

int main()
{
    while(true)
    {
        _testPin.SetOutput(Hal::OutputLevel::High);
        std::this_thread::sleep_for(std::chrono::seconds(10));

        _testPin.SetOutput(Hal::OutputLevel::Low);
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}